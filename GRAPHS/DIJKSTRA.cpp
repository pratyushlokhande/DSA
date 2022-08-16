#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w, bool bidir = true)
    {
        if (bidir)
        {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        else
        {
            adj[u].push_back(make_pair(v, w));
        }
    }

    void bfs(int src)
    {
        bool *visited = new bool[V]{false};
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cout << x << " ";
            for (auto it : adj[x])
            {
                auto node = it.first;
                if (!visited[node])
                {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
    }

    void dfs_helper(int src, bool *visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto it : adj[src])
        {
            auto node = it.first;
            if (!visited[node])
            {
                dfs_helper(node, visited);
            }
        }
    }

    void dfs(int src)
    {
        bool *visited = new bool[V]{false};
        dfs_helper(src, visited);
    }

    int dijkstra(int src, int dest)
    {
        int *dist = new int[V]{INT_MAX};
        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert(make_pair(dist[src], src));

        while (!s.empty())
        {
            auto it = s.begin();
            s.erase(it);

            int d = it->first;
            int node = it->second;

            for (auto nbr : adj[node])
            {
                int n = nbr.first;
                int w = nbr.second;

                if (dist[n] > d + w)
                {
                    // check if pair is already in set
                    auto x = s.find(make_pair(dist[n], n));
                    if (x != s.end())
                    {
                        s.erase(x);
                    }

                    // update distance if new distance is less than old distance
                    dist[n] = d + w;
                    s.insert(make_pair(dist[n], n));
                }
            }
        }
        return dist[dest];
    }
};

void solve()
{
    // code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

// take inputs from file
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
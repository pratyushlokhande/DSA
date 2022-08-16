#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    list<int> *adj_rev;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        adj_rev = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj_rev[w].push_back(v);
    }

    void dfs(int v, bool visited[], vector<int> &vis)
    {
        visited[v] = true;

        for (auto &x : adj[v])
        {
            if (!visited[x])
            {
                dfs(x, visited, vis);
            }
        }
        vis.push_back(v);
    }

    void rev_dfs(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        for (auto &x : adj_rev[v])
        {
            if (!visited[x])
            {
                rev_dfs(x, visited);
            }
        }
    }

    int kosaraju()
    {
        vector<int> vis;
        bool visited[V] = {false};
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, vis);
            }
        }

        reverse(vis.begin(), vis.end());
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for (auto &x : vis)
        {
            if (!visited[x])
            {
                cout << "Component " << ++cnt << " : ";
                rev_dfs(x, visited);
                cout << endl;
            }
        }
        return cnt;
    }
};

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    cout << g.kosaraju() << endl;
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
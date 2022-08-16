#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int V;
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        V = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] == -1)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int a = find(x);
        int b = find(y);

        if (a != b)
        {
            if (rank[a] > rank[b])
            {
                parent[b] = a;
                rank[b] += rank[a];
            }
            else
            {
                parent[a] = b;
                rank[a] += rank[b];
            }
        }
    }

    ~DSU()
    {
        parent.clear();
        rank.clear();
    }
};

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

static bool compare(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

class Graph
{
    int V;
    vector<Edge> edges;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back(Edge(u, v, w));
    }

    int kruksal()
    {
        sort(edges.begin(), edges.end(), compare);
        DSU dsu(V);
        int cost = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i].u;
            int y = edges[i].v;
            int w = edges[i].w;
            if (dsu.find(x) != dsu.find(y))
            {
                dsu.unite(x, y);
                cost += w;
            }
        }
        return cost;
    }

    ~Graph()
    {
        edges.clear();
    }
};

class PrimsGraph
{
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    PrimsGraph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int prims()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[v] > w)
                {
                    dist[v] = w;
                    pq.push(make_pair(w, v));
                }
            }
        }
        int cost = 0;
        for (int i = 1; i < V; i++)
        {
            cost += dist[i];
        }
        return cost;
    }
};

void solve()
{
    // code here
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << g.kruksal() << endl;
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
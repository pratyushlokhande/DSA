#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &graph, bool visited[], int src)
{
    visited[src] = true;

    int x = 1;
    for (auto &node : graph[src])
    {
        if (!visited[node])
        {
            x += dfs(graph, visited, node);
        }
    }
    return x;
}

int shortestPathLength(vector<vector<int>> &graph)
{
    int min_path = INT_MAX;
    int s = graph.size();
    bool visited[s] = {false};

    for (int i = 0; i < s; i++)
    {
        int p = dfs(graph, visited, i);
        min_path = min(min_path, p);
        memset(visited, false, sizeof(visited));
    }

    return min_path;
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << shortestPathLength(graph) << endl;
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
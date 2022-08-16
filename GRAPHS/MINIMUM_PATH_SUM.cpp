#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    set<pair<int, pair<int, int>>> s;
    dist[0][0] = grid[0][0];
    s.insert({dist[0][0], {0, 0}});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!s.empty())
    {
        auto it = s.begin();
        s.erase(it);

        int pwt = it->first;
        int i = it->second.first;
        int j = it->second.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 and nx < m and ny >= 0 and ny < n)
            {
                int d = grid[nx][ny];

                if (dist[nx][ny] > d + pwt)
                {
                    auto pr = s.find({dist[nx][ny], {nx, ny}});
                    if (pr != s.end())
                    {
                        s.erase(pr);
                    }

                    dist[nx][ny] = d + pwt;
                    s.insert({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    return dist[m - 1][n - 1];
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid) << endl;
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
#include <bits/stdc++.h>
using namespace std;

int m, n;

int dfs(vector<vector<int>> &mat, int i, int j)
{
    if (mat[i][j] == 0)
    {
        return 0;
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    int min_dist = INT_MAX;

    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (nx >= 0 and nx < m and ny >= 0 and ny < n)
        {
            int d = dfs(mat, nx, ny);
            if (d != -1)
            {
                min_dist = min(min_dist, d + 1);
            }
        }
    }

    if (min_dist == INT_MAX)
    {
        return -1;
    }

    return min_dist;
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    m = mat.size();
    n = mat[0].size();

    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                ans[i][j] = dfs(mat, i, j);
            }
        }
    }

    return ans;
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> ans = updateMatrix(mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
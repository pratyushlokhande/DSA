#include <bits/stdc++.h>
using namespace std;

int getMinPathSum(vector<vector<int>> &grid, vector<vector<int>> &dp, int r, int c, int s, int e)
{
    if (s >= r - 2 || e >= c - 2)
    {
        return 0;
    }
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    int curr_sum = INT_MAX;

    for (int i = 0; i < 2; i++)
    {
        int s = grid[s][e] + getMinPathSum(grid, dp, r, c, s + dx[i], e + dy[i]);
        curr_sum = min(curr_sum, s);
    }
    return dp[s][e] = curr_sum;
}

int minPathSum(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));

    return getMinPathSum(grid, dp, r, c, 0, 0);
}

void solve()
{
    // code here
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
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
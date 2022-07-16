#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp)
{
    if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n)
    {
        return 1;
    }

    if (maxMove == 0)
    {
        return 0;
    }

    if (dp[startRow][startColumn][maxMove] != -1)
    {
        return dp[startRow][startColumn][maxMove];
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int total_moves = 0;

    for (int i = 0; i < 4; i++)
    {
        total_moves = (total_moves + findPaths(m, n, maxMove - 1, startRow + dx[i], startColumn + dy[i], dp)) % MOD;
    }
    return dp[startRow][startColumn][maxMove] = total_moves % MOD;
}

void solve()
{
    // code here
    int m, n, maxMove, startRow, startColumn;
    cin >> m >> n >> maxMove >> startRow >> startColumn;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
    cout << findPaths(m, n, maxMove, startRow, startColumn, dp) << endl;
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
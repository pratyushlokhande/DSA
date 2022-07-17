#include <bits/stdc++.h>
using namespace std;

int moveRobot(int m, int n, int currX, int currY, vector<vector<int>> &dp)
{
    if (currX == n - 1 || currY == m - 1)
    {
        return dp[currY][currX] = 1;
    }

    if (dp[currY][currX] != -1)
    {
        return dp[currY][currX];
    }

    // right move
    int right = moveRobot(m, n, currX + 1, currY, dp);

    // move left
    int down = moveRobot(m, n, currX, currY + 1, dp);

    return dp[currY][currX] = right + down;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return moveRobot(m, n, 0, 0, dp);
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;

    cout << uniquePaths(m, n) << endl;
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
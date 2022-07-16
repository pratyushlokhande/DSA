#include <bits/stdc++.h>
using namespace std;

// Wines Problem

int profitHelper(vector<int> &v, vector<vector<int>> &dp, int l, int r, int profit)
{
    // base case
    if (r == l)
    {
        return v[l] * profit;
    }

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    // recursive case
    // left is taken right ignored
    int lt = v[l] * profit + profitHelper(v, dp, l + 1, r, profit + 1);

    // right taken left ignored
    int rt = v[r] * profit + profitHelper(v, dp, l, r - 1, profit + 1);

    return dp[l][r] = max(lt, rt);
}

int profitHelperTD(vector<int> &v, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int l = 0;
    int r = n - 1;
}

int maxProfit(vector<int> &bottles, int n)
{
    // n=0
    if (n == 0)
    {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return profitHelper(bottles, dp, 0, n - 1, 1);
}

void solve()
{
    // code here
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxProfit(v, n) << endl;
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
#include <bits/stdc++.h>
using namespace std;

// Maximum subarray sum

int maxSubArraySum(vector<int> &v, int n)
{
    int dp[n] = {0};

    dp[0] = v[0] > 0 ? v[0] : 0;
    int max_till_now = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + v[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        max_till_now = max(max_till_now, dp[i]);
    }
    return max_till_now;
}

// Space optimised Max Subarray Sum
int maxSubArraySumSpaceOptimised(vector<int> &v, int n)
{
    int current_sum = 0;
    int max_till_now = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum += v[i];
        if (current_sum < 0)
        {
            current_sum = 0;
        }
        max_till_now = max(max_till_now, current_sum);
    }
    return max_till_now;
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

    cout << maxSubArraySum(v, n) << endl;
    cout << maxSubArraySumSpaceOptimised(v, n) << endl;
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
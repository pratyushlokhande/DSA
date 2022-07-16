#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    int max_till_now = 0;
    for (int i = 0; i < n; i++)
    {
        int prev = 0;
        for (int k = i; k >= 0; k--)
        {
            if (nums[i] > nums[k])
            {
                prev = max(dp[k], prev);
            }
        }
        dp[i] += (prev + 1);
        max_till_now = max(max_till_now, dp[i]);
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

    cout << lengthOfLIS(v) << endl;
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
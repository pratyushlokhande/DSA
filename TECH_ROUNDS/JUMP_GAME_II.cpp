#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int idx, vector<int> &dp)
{
    // base case
    if (idx >= (nums.size() - 1))
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int jp = nums[idx];

    int min_till_now = INT_MAX;

    for (int i = 1; i <= jp; i++)
    {
        int k = helper(nums, idx + i, dp);

        if (k == INT_MAX)
        {
            continue;
        }

        min_till_now = min(min_till_now, 1 + k);
    }

    return dp[idx] = min_till_now;
}
int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
}

int jumpII(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;
    int jump = 1, curr_jump = nums[0], max_jump = nums[0];
    int idx = 0;
    while (idx < nums.size() - 1)
    {
        max_jump = max(max_jump, idx + nums[idx]);

        if (idx == curr_jump)
        {
            jump++;
            curr_jump = max_jump;
        }

        idx++;
    }
    return jump;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << jumpII(nums) << endl;
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
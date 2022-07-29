#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int max_rob = 0;

    int diff = nums.size() - 1;

    if (diff == 0)
    {
        return nums[0];
    }
    else if (diff == 1)
    {
        return max(nums[0], nums[1]);
    }

    while (diff > 1)
    {
        int curr_ct = 0;
        // int st = 0, ed = diff;

        for (int i = 0; i < nums.size(); i += diff)
        {
            curr_ct += nums[i];
        }
        max_rob = max(max_rob, curr_ct);
        cout << "diff => " << diff << "|" << max_rob << endl;
        --diff;
    }
    return max_rob;
}

int helper(vector<int> &nums, vector<int> &dp, int idx)
{
    if (idx == nums.size())
    {
        return 0;
    }
    int rob1 = 0, rob2 = 0;

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    if (idx == nums.size() - 1)
    {
        return dp[idx] = nums[idx];
    }

    // rob current house
    if (idx <= nums.size() - 2)
    {
        rob1 = nums[idx] + helper(nums, dp, idx + 2);
        rob2 = helper(nums, dp, idx + 1);
        return max(rob1, rob2);
    }
    else
    {
        return helper(nums, dp, idx + 1);
    }

    // not rob current house

    return dp[idx] = max(rob1, rob2);
}

int robII(vector<int> &nums)
{
    int idx = 0;
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return helper(nums, dp, idx);
}

int robIII(vector<int> &nums)
{
    int n = nums.size();
    int *d = new int[n + 1];
    d[0] = nums[0];
    d[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        d[i] = max(d[i - 1], d[i - 2] + nums[i]);
    }
    return d[n - 1];
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
    cout << robII(nums) << endl;
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
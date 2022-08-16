#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, int target, int idx, int &count)
{
    if (target == 0)
    {
        count++;
        return;
    }
    if (idx == nums.size())
        return;
    cout << "idx " << idx << " target " << target << endl;
    helper(nums, target + nums[idx], idx + 1, count);
    helper(nums, target - nums[idx], idx + 1, count);
}

int findTargetSumWays(vector<int> &nums, int target, int &count)
{
    helper(nums, target, 0, count);
    return count;
}

void solve()
{
    // code here
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int count = 0;
    cout << findTargetSumWays(A, k, count) << endl;
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
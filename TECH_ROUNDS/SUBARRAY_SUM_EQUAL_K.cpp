#include <bits/stdc++.h>
using namespace std;

int subarraySumII(vector<int> &nums, int k)
{
    set<int> s;
    s.insert(0);
    s.insert(nums[0]);
    int res = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
        s.insert(nums[i]);
    }

    for (auto x : s)
    {
        if (s.find(x - k) != s.end())
        {
            res++;
        }
    }
    return res;
}
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int prefSum = 0, ans = 0;
    m[prefSum] = 1;
    for (auto x : nums)
    {
        prefSum += x;
        int f = prefSum - k;
        if (m.find(f) != m.end())
        {
            ans += m[f];
        }
        m[prefSum]++;
    }
    return ans;
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

    int k;
    cin >> k;
    cout << subarraySum(nums, k) << endl;
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
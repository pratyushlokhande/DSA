#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long nCr(int n, int r)
{
    if (r > n - r)
        r = n - r;
    long long ans = 1;
    int i;

    for (int i = 1; i <= r; i++)
    {
        ans *= (n - r + i);
        ans /= i;
    }

    return ans;
}

int evenproduct(vector<int> nums)
{
    int s = nums.size();
    int ct_even = 0;
    vector<int> indexes;

    for (int i = 0; i < s; i++)
    {
        if ((nums[i] & 1) == 0)
        {
            ct_even++;
            indexes.push_back(i);
        }
    }
    if (s == 3 && ct_even > 0)
    {
        return 1;
    }
    else if (s == ct_even)
    {
        int res = nCr(s, 3);
        return res;
    }
    int calc1, calc2, res = 0;
    for (int i = 1; i <= ct_even && i <= 3; i++)
    {
        calc1 = nCr(ct_even, i);
        for (int k = i - 1; k < indexes.size(); k++)
        {
            int p = s - i - indexes[k] + 1;
            if (p >= 3)
            {
                calc2 = nCr(p, 3 - i);

                res = (res + ((calc1 * calc2) % MOD)) % MOD;
            }
        }
    }
    return res;
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
    cout << evenproduct(nums) << endl;
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
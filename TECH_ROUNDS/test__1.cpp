#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int> &arr)
{
    int odd = 0, even = 0, ans = 0, MOD = (int)1e9 + 7;
    for (auto number : arr)
    {
        if (number % 2 == 0)
            even++;
        else
        {
            swap(odd, even);
            odd++;
        }
        ans = (ans % MOD + odd % MOD) % MOD;
    }
    return ans;
}

int countDivisors(vector<int> &a, int n)
{
    vector<int> divCount;
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 1; j <= (a[i] / 2); j++)
        {
            if (a[i] % j == 0)
            {
                cnt++;
            }
        }
        cnt++;
        divCount.push_back(cnt);
    }
    return numOfSubarrays(divCount);
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << countDivisors(a, n);
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
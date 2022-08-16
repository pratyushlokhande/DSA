#include <bits/stdc++.h>
using namespace std;
typedef long ll;
int gethash(string s)
{
    int hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash += (i % 2) * (i + 1) * (s[i] - 'a' + 1);
    }
    return hash;
}
// 238

bool solve(ll mid, ll n)
{

    ll x = 0, y = 0;
    while (n != 0)
    {
        if (n < mid)
        {
            x += n;
            n = 0;
        }
        else
        {
            x += mid;
            n -= mid;
        }
        y += n / 5;
        n -= n / 5;
    }
    return x >= y;
}

void solve()
{
    // code here
    // string s, k;
    // cin >> s >> k;
    // cout << gethash(s) << " " << gethash(k) << endl;
    long n = 40;
    ll high = n;
    ll low = 0;
    ll ans = high;
    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (mid == 0)
        {
            break;
        }

        if (solve(mid, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans;
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
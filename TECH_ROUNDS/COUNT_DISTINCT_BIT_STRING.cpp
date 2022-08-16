#include <bits/stdc++.h>
using namespace std;

int countSetBits(string s, int)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
    }
    return count;
}

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int countSetBits(int num, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (num & (1 << i))
        {
            count++;
        }
    }
    return count;
}

void solve()
{
    // code here
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }

    int count = 0;
    int num = s[0];
    for (int i = 1; i < k; i++)
    {
        num = num & s[i];
    }
    int sb = n - countSetBits(num, n);
    count = pow(2, sb);
    cout << count << endl;
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
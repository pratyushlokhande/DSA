#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int flag = a[0];
    a[0] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        a[i] = flag;
        flag = x;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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
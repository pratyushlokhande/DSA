#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int T, n;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // rotate array
        for (int i = 0; i < n / 2; i++)
        {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    // init
    ios_base::sync_with_stdio(false);
    cin.tie(0);

// take inputs from file
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // solution
    solve();

    return 0;
}

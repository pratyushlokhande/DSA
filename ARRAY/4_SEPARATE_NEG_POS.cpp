#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int aux[n];

    int idx = 0;
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            aux[idx] = a[i];
            idx++;
        }
        else
        {
            a[counter] = a[i];
            counter++;
        }
    }

    for (int i = counter; i < n; i++)
    {
        a[i] = aux[i - counter];
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
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
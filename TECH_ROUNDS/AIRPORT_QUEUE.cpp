#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minutes = 0;

    while (true)
    {
        int x = m;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= minutes)
            {
                int val = floor(minutes / arr[i]);
                if (x - val >= 0)
                {
                    x -= val;
                }
            }
        }

        if (x == 0)
        {
            break;
        }
        minutes++;
    }

    cout << minutes;
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
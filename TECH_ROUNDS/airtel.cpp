#include <bits/stdc++.h>
using namespace std;

// 1 2 3 6 3 6 1
// n = 0 - 1000

// Input : arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
// Output : 3 3 4 5 5 5 6

// prev_max = 3
void solve()
{
    // code here
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (auto x : m)
    {
        if (x.second > 1)
        {
            cout << x.first;
        }
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
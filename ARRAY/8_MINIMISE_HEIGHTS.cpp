#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // sort the array
    sort(arr, arr + n);

    int minDiff = arr[n - 1] - arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < k)
        {
            continue;
        }

        int maxD = max(arr[i] + k, arr[n - 1] - k);
        int minD = min(arr[i + 1] - k, arr[0] + k);

        minDiff = min(minDiff, maxD - minD);
    }

    cout << minDiff << endl;
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
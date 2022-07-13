#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum > max_sum)
            max_sum = curr_sum;
        if (curr_sum < 0)
            curr_sum = 0;
    }
    cout << max_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

// take inputs from file
// take inputs from file
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
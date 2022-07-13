#include <bits/stdc++.h>
using namespace std;

int jumpHelper(int arr[], int n, int idx)
{
    if (arr[idx] == 0)
    {
        return -1;
    }
    else if (idx + arr[idx] >= n - 1)
    {
        return 1;
    }

    int minJump = INT_MAX;

    for (int i = 1; i <= arr[idx]; i++)
    {
        int jump = jumpHelper(arr, n, idx + i);
        if (jump != -1)
        {
            minJump = min(minJump, jump + 1);
        }
    }

    if (minJump == INT_MAX)
    {
        return -1;
    }

    return minJump;
}

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

    cout << jumpHelper(arr, n, 0) << endl;
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
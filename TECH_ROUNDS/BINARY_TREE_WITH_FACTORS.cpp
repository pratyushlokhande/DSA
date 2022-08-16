#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int numFactoredBinaryTrees(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    unordered_map<int, long> m;

    int s = arr.size();
    m[arr[0]] = 1;

    int count;
    for (int i = 1; i < s; i++)
    {
        count = 1;
        for (int j = 0; j < i; j++)
        {

            if (arr[i] % arr[j] == 0 and m.find(arr[i] / arr[j]) != m.end())
            {
                count += m[arr[j]] * m[arr[i] / arr[j]];
            }
        }
        m[arr[i]] = count;
    }
    long res = 0;
    for (auto &x : m)
    {
        res = (res + x.second) % MOD;
    }

    return res % MOD;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << numFactoredBinaryTrees(A) << endl;
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
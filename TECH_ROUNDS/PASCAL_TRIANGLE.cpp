#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{

    if (n == r || r == 0)
    {
        return 1;
    }
    int n_fact = 1;

    if (r > (n - r))
    {
        r = n - r;
    }

    for (int i = 0; i < r; i++)
    {
        n_fact *= (n - i);
    }
    int r_fact = 1;
    for (int i = 1; i <= r; i++)
    {
        r_fact *= i;
    }
    return n_fact / r_fact;
}
vector<vector<int>> generatePascal(int numRows)
{
    vector<vector<int>> res;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> r;
        int x = i;
        while (x >= 0)
        {
            r.push_back(nCr(i, x));
            x--;
        }
        res.push_back(r);
    }
    return res;
}
vector<vector<int>> generatePascalOptimised(int numRows)
{
    vector<vector<int>> res;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> r(i + 1);
        int x = i;
        r[0] = 1;
        r[i] = 1;
        for (int j = 1; j < i; j++)
        {
            r[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(r);
    }
    return res;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<vector<int>> res = generatePascalOptimised(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
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
#include <bits/stdc++.h>
using namespace std;

int helper(vector<pair<int, int>> &A, vector<pair<int, int>> &B, int W, bool incA, bool incB)
{
}

int getMaxProteinContentUnderWeightW(vector<pair<int, int>> &A, vector<pair<int, int>> &B, int W)
{
    int n = A.size();
    int m = B.size();
}

void solve()
{
    // code here
    int a, b, wt;
    cin >> a >> b >> wt;
    vector<pair<int, int>> typeA(a);
    vector<pair<int, int>> typeB(b);

    for (int i = 0; i < a; i++)
    {
        cin >> typeA[i].first;
        cin >> typeA[i].second;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> typeB[i].first;
        cin >> typeB[i].second;
    }

    cout << getMaxProteinContentUnderWeightW(typeA, typeB, wt) << endl;
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
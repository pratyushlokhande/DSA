#include <bits/stdc++.h>
using namespace std;

// search matrix II
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    if (m == 0)
        return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else
            i++;
    }
    return false;
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    cout << (searchMatrix(matrix, target) ? "YES" : "NO") << endl;
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
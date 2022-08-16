#include <bits/stdc++.h>
using namespace std;

int n, m;

// four way dfs
int dfs(vector<vector<int>> &A, int x, int y, vector<vector<bool>> &visited)
{
    if (x == n - 1 || y == m - 1)
        return A[x][y];

    visited[x][y] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int f = INT_MAX;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        cout << nx << " " << ny << endl;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
        {
            f = min(f, dfs(A, nx, ny, visited));
        }
        else
        {
            cout << "here" << endl;
        }
        // f = min(f, dfs(A, nx, ny, visited));
    }

    return A[x][y] + f;
}

int minimumCostPath(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();

    // visited matrix
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    return dfs(A, 0, 0, visited);
}

void solve()
{
    // code here
    int r, c;
    cin >> r >> c;
    vector<vector<int>> A(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << minimumCostPath(A) << endl;
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
#include <bits/stdc++.h>
using namespace std;

bool isIntersecting(vector<int> &c1, vector<int> &c2)
{
    int x1 = c1[0], y1 = c1[1], r1 = c1[2];
    int x2 = c2[0], y2 = c2[1], r2 = c2[2];

    int d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    return d <= r1 + r2;
}

bool isCirclesConnected(vector<vector<int>> circles)
{
    queue<vector<int>> q;
    vector<bool> visited(circles.size(), false);
    q.push(circles[0]);
    visited[0] = true;
    int idx = 1;

    while (!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();

        for (int i = idx; i < circles.size(); i++)
        {
            if (isIntersecting(curr, circles[i]) && !visited[i])
            {
                q.push(circles[i]);
                visited[i] = true;
            }
        }

        if (q.empty() and idx < circles.size())
        {
            return false;
        }

        idx++;
    }
    return true;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<vector<int>> circles(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> circles[i][0] >> circles[i][1] >> circles[i][2];
    }
    cout << (isCirclesConnected(circles) ? "YES" : "NO") << endl;
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
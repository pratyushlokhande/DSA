#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int x, int y)
    {
        // printf("%d -> %d\n", x, y);
        adjList[x].push_back(y);
    }

    int bfs(int src, int dest)
    {
        map<int, int> dist;
        for (auto i : adjList)
        {
            dist[i.first] = INT_MAX;
        }

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (auto x : adjList[node])
            {
                if (dist[x] == INT_MAX)
                {
                    dist[x] = dist[node] + 1;
                    q.push(x);
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int tot = n * n + 1;

    Graph g;
    for (int i = 0; i < tot; i++)
    {

        for (int dice = 1; dice <= 6; dice++)
        {
            int npos = i + dice - 1;
            // cout << "i " << i << " dice " << dice << " npos " << npos % n << endl;
            int r = npos / n;
            int c = npos % n;

            if (r % 2 != 0)
            {
                c = n - c - 1;
            }

            // cout << "r " << r << " c " << c << endl;

            if (npos < tot)
            {
                if (board[n - r - 1][c] == -1)
                {
                    g.addEdge(i, npos);
                }
                else
                {
                    // while (board[n - r - 1][c] != -1)
                    // {
                    //     npos = board[n - r - 1][c];
                    //     r = npos / n;
                    //     if (r == tot)
                    //     {
                    //         r -= 1;
                    //     }
                    //     c = (npos - 1) % n;
                    //     if (r % 2 != 0)
                    //     {
                    //         c = n - c - 1;
                    //     }
                    // }
                    g.addEdge(i, board[n - r - 1][c]);
                }
            }
        }
    }
    g.addEdge(tot - 1, tot - 1);

    return g.bfs(0, tot - 1);
}

int snakeLadder(vector<int> &board)
{
    int n = board.size();
    Graph g;
    for (int i = 0; i < n; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int npos = i + dice;
            npos += board[npos];

            if (npos < n)
            {
                g.addEdge(i, npos);
            }
        }
    }
    g.addEdge(n - 1, n - 1);
    return g.bfs(0, n - 1);
}

vector<int> getBoard(vector<vector<int>> &board)
{
    int n = board.size();
    int tot = n * n;
    vector<int> B(n * n + 1, 0);

    for (int i = 1; i <= n * n; i++)
    {
        int r = (i - 1) / n;
        int c = (i - 1) % n;

        if (r % 2 != 0)
        {
            c = n - c - 1;
        }

        if (board[n - r - 1][c] != -1)
        {
            B[i] = board[n - r - 1][c] - i;
        }
    }
    return B;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<int> B = getBoard(board);

    cout << snakeLadder(B) << endl;
    // cout << snakesAndLadders(board) << endl;
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
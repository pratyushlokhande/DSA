#include <bits/stdc++.h>
using namespace std;

class DSU // O(n)
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int x)
    { // O(n)
        if (parent[x] == -1)
            return x;
        return parent[x] = find(parent[x]);
    }

    int path_compression_find(int x)
    { // O(log(n)) ~ O(1)
        if (parent[x] == -1)
            return x;
        return parent[x] = path_compression_find(parent[x]);
    }

    void Union(int x, int y)
    { // O(n)
        int a = find(x);
        int b = find(y);
        if (a != b)
            parent[a] = b;
    }

    void union_by_rank(int x, int y)
    { // O(log(n)) ~ O(1)
        int a = find(x);
        int b = find(y);
        if (a != b)
        {
            if (rank[a] > rank[b])
            {
                parent[b] = a;
                rank[b] += rank[a];
            }
            else
            {
                parent[a] = b;
                rank[a] += rank[b];
            }
        }
    }
};

void solve()
{
    // code here
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
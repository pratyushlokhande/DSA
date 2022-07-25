// Sample code to read input and write output:

/*
#include <iostream>

using namespace std;

int main()
{
    char name[20];
    cin >> name;                     // Read input from STDIN
    cout << "Hello " << name;        // Write output to STDOUT
    return 0;
}
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }

    bool union_sets(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);

        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int mst_weight(vector<vector<int>> &edges, int n)
{
    DSU dsu(n);

    int ans = 0;

    sort(edges.begin(), edges.end());

    int len = edges.size();

    for (int k = 0; k < len; k++)
    {
        // vector<int> edge = edges[k];
        if (dsu.union_sets(edges[k][1], edges[k][2]))
        {
            ans += edges[k][0];
        }
    }
    return ans;
}

// class Compare {
// 	public:
// 	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
// 		return a.first > b.first;
// 	}
// };

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

// take inputs from file
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // Write your code here
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> data(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        data[i] = make_pair(x, y);
        // cin >> data[i].first >> data[i].second;
    }

    vector<pair<int, int>> res;

    for (int i = 1; i <= n; i++)
    {
        int nodes = data[i].first;
        int edges = data[i].second;

        vector<vector<int>> edges_vec;

        for (int j = 0; j < edges; j++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(w);
            edges_vec.push_back(v);
        }

        int mst = mst_weight(edges_vec, nodes);

        res.push_back(make_pair(mst, i));
    }

    // sort(res.begin(), res.end(), [&](const pair<int, int> a, const pair<int, int> b) {
    // 	return a.first > b.first;
    // });
    sort(res.begin(), res.end(), compare);
    cout << res[k - 1].second << " " << res[k - 1].first;
    return 0;
}
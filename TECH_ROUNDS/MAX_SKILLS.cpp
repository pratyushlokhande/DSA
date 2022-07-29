#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int skill;
    int package;

    Employee(int s, int p)
    {
        skill = s;
        package = p;
    }
};

int knapsack(vector<pair<int, int>> &data, int idx, int budget)
{
    if (budget <= 0 || idx == data.size())
    {
        return 0;
    }

    if (data[idx].first > budget)
    {
        return 0;
    }

    // include
    int inc = data[idx].second + knapsack(data, idx + 1, budget - data[idx].first);
    // exclude
    int exc = knapsack(data, idx + 1, budget);

    return max(inc, exc);
}

void solve()
{
    // code here
    int N, k, a, b;
    cin >> N >> k;

    vector<Employee *> employees(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        employees[i] = new Employee(a, b);
    }

    int Q;
    cin >> Q >> k;

    map<int, vector<int>> m;
    bool visited[N] = {0};

    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        if (m.count(a - 1))
        {
            for (auto x : m[a - 1])
            {
                m[x].push_back(b - 1);
            }
        }

        if (m.count(b - 1))
        {
            for (auto x : m[b - 1])
            {
                m[x].push_back(a - 1);
            }
        }

        m[a - 1].push_back(b - 1);
        m[b - 1].push_back(a - 1);
    }

    int budget;
    cin >> budget;

    vector<pair<int, int>> groups;
    for (int i = 0; i < N; i++)
    {
        if (m.count(i) && !visited[i])
        {
            auto v = m[i];
            int tot_sal = employees[i]->package;
            int tot_skill = employees[i]->skill;
            cout << "i " << i << " => " << endl;
            for (auto x : v)
            {
                cout << x << " => " << employees[x]->skill << " " << employees[x]->package << endl;
                tot_sal += employees[x]->package;
                tot_skill += employees[x]->skill;
                visited[x] = true;
            }
            groups.push_back({tot_sal, tot_skill});
        }
        else if (!visited[i])
        {
            groups.push_back({employees[i]->package, employees[i]->skill});
        }
        visited[i] = true;
    }

    sort(groups.begin(), groups.end());
    for (auto x : groups)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << knapsack(groups, 0, budget);
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
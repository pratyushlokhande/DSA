#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    for (int i = 0; i < gas.size(); i++)
    {
        int fuel = gas[i];
        int amt = cost[i];
        int diff = gas[i] - cost[i];
        int idx = (i + 1) % gas.size();

        if (diff < 0)
            continue;

        while (true)
        {
            // cout << "i: " << i << " idx: " << idx << " diff : " << diff << endl;
            if (idx == i)
            {
                return i;
            }

            if (diff <= 0)
            {
                break;
            }
            if (diff + gas[idx] < cost[idx])
            {
                break;
            }
            diff = diff + gas[idx] - cost[idx];
            idx = (idx + 1) % gas.size();
        }
    }
    return -1;
}

// @method: 2
int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    int tank = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    return (tank >= 0) ? start : -1;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    cout << canCompleteCircuit2(gas, cost) << endl;
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
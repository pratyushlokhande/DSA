#include <bits/stdc++.h>
using namespace std;

vector<int> findInputArray(string s)
{
    vector<int> res;
    int idx = 0;
    while (s[idx] != '\0' and idx < s.length())
    {
        int num = 0;
        while (s[idx] != ',' and s[idx] != '\0')
        {
            num = num * 10 + (s[idx] - '0');
            idx++;
        }
        idx++;
        res.push_back(num);
    }
    return res;
}

string generateOutput(string s, int c)
{
    vector<int> in = findInputArray(s);

    // airport
    stack<queue<int>> airport;
    int i = 0;
    while (i < in.size())
    {
        queue<int> q;
        int rem = c;
        while (in[i] <= rem && i < in.size())
        {
            q.push(in[i]);
            rem -= in[i];
            i++;
        }
        if (q.empty())
        {
            i++;
        }
        airport.push(q);
    }

    // output
    string res = "";
    while (!airport.empty())
    {
        queue<int> q = airport.top();
        airport.pop();
        while (!q.empty())
        {
            res += to_string(q.front());
            q.pop();
            // res += ",";
            if (!q.empty())
            {
                res += ",";
            }
        }
        if (!airport.empty())
        {
            res += ",";
        }
    }
    return res;
}

void solve()
{
    // code here
    string s;
    int c;
    cin >> s;
    cin >> c;

    cout << generateOutput(s, c);
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
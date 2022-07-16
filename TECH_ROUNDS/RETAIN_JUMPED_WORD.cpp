#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int X;
    cin >> X;

    string s;
    cin >> s;
    string res;
    int len = s.length();
    while (X--)
    {
        res = "";
        stack<char> st;
        for (int i = 0; i < len; i++)
        {
            if (i % 2 == 0)
            {
                res += s[i];
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        s = res;
    }

    cout << res << endl;
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
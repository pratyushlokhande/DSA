#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    bool nature = false;

    int num = 0, val, idx = 0;
    bool legalVal = false;

    for (char ch : s)
    {
        if (ch <= 'a' and ch >= 'z')
        {
            break;
        }

        if (ch == '-')
        {
            nature = true;
            continue;
        }

        if (ch >= '0' and ch <= '9')
        {
            val = ch - '0';

            if (legalVal)
            {
                num = num * 10 + val;
                continue;
            }

            if (val != 0 and !legalVal)
            {
                num = num * 10 + val;
                legalVal = true;
            }
        }
    }
    if (nature)
    {
        return -1 * num;
    }

    return num;
}

void solve()
{
    // code here
    string s;
    cin >> s;

    cout << myAtoi(s) << endl;
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
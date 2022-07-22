#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    multiset<char> ms;

    for (auto ch : s)
    {
        ms.insert(ch);
    }

    for (auto ch : t)
    {
        auto pos = ms.find(ch);
        if (pos != ms.end())
        {
            ms.erase(pos);
        }
        else
        {
            return false;
        }
    }

    return ms.empty();
}

void solve()
{
    // code here
    string s, t;
    cin >> s >> t;
    cout << (isAnagram(s, t) ? "YES" : "NO") << endl;
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
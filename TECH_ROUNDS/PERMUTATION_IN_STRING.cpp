#include <bits/stdc++.h>
using namespace std;

string str;

bool checkPresence(string s)
{
    int i = 0;
    int j = s.length();
    int ml = str.length();

    while ((i + j) <= ml)
    {
        if (s == str.substr(i, j))
        {
            return true;
        }
        i++;
    }
    return false;
}

bool permutation(string s, int idx)
{
    if (s[idx] == '\0')
    {
        return checkPresence(s);
    }

    for (int i = idx; s[i] != '\0'; i++)
    {
        swap(s[i], s[idx]);
        if (permutation(s, idx + 1))
        {
            return true;
        }
        swap(s[i], s[idx]);
    }

    return false;
}

bool checkInclusion(string s1, string s2)
{

    if (s1.length() > s2.length())
    {
        return false;
    }
    str = s2;
    return permutation(s1, 0);
}

bool slidingWindowMethod(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }

    map<char, int> m;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        m[s1[i]]++;
    }

    int s = 0;
    int e = s1.length() - 1;
    map<char, int> x;

    for (int i = 0; i <= e; i++)
    {
        x[s2[i]]++;
    }

    while (s2[e] != '\0')
    {

        bool flag = true;

        for (auto p : x)
        {
            if (m[p.first] != p.second)
            {
                flag = false;
            }
        }

        if (flag)
            return true;

        x[s2[s]]--;
        s++;
        e++;
        x[s2[e]]++;
    }

    return false;
}

void solve()
{
    // code here
    string s1, s2;
    cin >> s1 >> s2;
    // cout << (checkInclusion(s1, s2) ? "YES" : "NO") << endl;
    cout << (slidingWindowMethod(s1, s2) ? "YES" : "NO") << endl;
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
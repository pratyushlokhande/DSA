#include <bits/stdc++.h>
using namespace std;

// bool isAnagram(string x, multiset<char> s)
// {
//     // multiset<char> s = k;
//     // cout << x << endl;
//     for (auto ch : x)
//     {
//         auto pos = s.find(ch);

//         if (pos != s.end())
//         {
//             s.erase(pos);
//         }
//         else
//         {
//             return false;
//         }
//     }

//     return s.empty();
// }

// vector<int> findAnagrams(string s, string p)
// {
//     vector<int> res;

//     if (s.length() < p.length())
//     {
//         return res;
//     }

//     multiset<char> k;

//     for (auto ch : p)
//     {
//         k.insert(ch);
//     }

//     int start = 0;
//     int end = p.length();

//     while (start < s.length() - end + 1)
//     {
//         string substr = s.substr(start, end);
//         bool flag = isAnagram(substr, k);
//         if (flag)
//         {
//             res.push_back(start);
//         }
//         ++start;
//     }

//     return res;
// }

bool isAnagram(string x, string p, int len)
{
    sort(x.begin(), x.end());

    for (int i = 0; i < len; i++)
    {
        if (x[i] != p[i])
        {
            return false;
        }
    }

    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;

    if (s.length() < p.length())
    {
        return res;
    }

    int start = 0;
    int end = p.length();
    sort(p.begin(), p.end());

    while (start < s.length() - end + 1)
    {
        string substr = "";
        for (int i = start; i < start + end; i++)
        {
            substr += s[i];
        }

        if (isAnagram(substr, p, end))
        {
            res.push_back(start);
        }
        ++start;
    }

    return res;
}

void solve()
{
    // code here
    string s, p;
    cin >> s >> p;

    vector<int> res = findAnagrams(s, p);
    // cout << (isAnagram("abc", {'a', 'b', 'c'}) ? "YES" : "NO") << endl;
    for (auto i : res)
    {
        cout << i << " ";
    }
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
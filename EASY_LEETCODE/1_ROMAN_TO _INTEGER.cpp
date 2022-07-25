#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int i = 0;
        int l = s.length();

        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int num = 0;

        while (i < l)
        {
            if (m[s[i]] < m[s[i + 1]] && i < (l - 1))
            {
                num += (m[s[i + 1]] - m[s[i]]);
                i += 2;
            }
            else
            {
                num += m[s[i]];
                i += 1;
            }
        }
        return num;
    }
};
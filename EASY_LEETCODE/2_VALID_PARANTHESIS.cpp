#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> k;

        map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        for (auto x : s)
        {
            if (!k.empty())
            {
                char p = k.top();
                if (m[p] == x)
                {
                    k.pop();
                }
                else
                {
                    k.push(x);
                }
            }
            else
            {
                k.push(x);
            }
        }

        if (!k.empty())
        {
            return false;
        }

        return true;
    }
};
class Solution
{
public:
    bool check(string s, string t)
    {
        unordered_map<char, char> m;
        for (int i = 0; i < s.length(); i++)
        {

            if (m.count(s[i]) == 0)
            {
                m[s[i]] = t[i];
            }
            else
            {

                if (m[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t)
    {
        return check(s, t) and check(t, s);
    }
};
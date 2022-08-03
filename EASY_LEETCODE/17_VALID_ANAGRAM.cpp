class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        //         multiset<char> ms;

        //         for (auto ch : s)
        //         {
        //             ms.insert(ch);
        //         }

        //         for (auto ch : t)
        //         {
        //             auto pos = ms.find(ch);
        //             if (pos != ms.end())
        //             {
        //                 ms.erase(pos);
        //             }
        //             else
        //             {
        //                 return false;
        //             }
        //         }

        //         return ms.empty();
        if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // for(int i=0 ; i<s.length() ; i++) {
        //     if (s[i] != t[i]) {
        //         return false;
        //     }
        // }

        return s == t;
    }
};
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int res = 0;

        multiset<char> strmap;
        for (auto ch : chars)
        {
            strmap.insert(ch);
        }

        for (auto word : words)
        {
            auto flag = strmap;
            bool good_string = true;

            for (auto ch : word)
            {
                auto pos = flag.find(ch);
                if (pos != flag.end())
                    flag.erase(pos);
                else
                {
                    good_string = false;
                    break;
                }
            }

            if (good_string)
            {
                res += word.length();
            }
        }

        return res;
    }
};
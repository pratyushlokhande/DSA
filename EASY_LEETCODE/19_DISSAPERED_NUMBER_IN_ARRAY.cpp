class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        set<int> s;
        for (int i = 1; i <= nums.size(); i++)
            s.insert(i);

        for (int num : nums)
        {
            auto pos = s.find(num);
            if (pos != s.end())
                s.erase(pos);
        }
        vector<int> res(s.begin(), s.end());
        return res;
    }
};
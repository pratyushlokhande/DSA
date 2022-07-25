class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int k = nums.size() / 2;

        map<int, int> m;

        for (int n : nums)
        {
            m[n]++;

            if (m[n] > k)
            {
                return n;
            }
        }
        return -1;
    }

    int majorityElementII(vector<int> &nums)
    {
        int el = -1, counter = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (counter == 0)
            {
                el = nums[i];
                counter++;
            }

            else if (el == nums[i])
            {
                counter++;
            }

            else
            {
                counter--;
            }
        }
        return el;
    }
};
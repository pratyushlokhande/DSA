class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int s = nums.size();
        while (k--)
        {
            int flag = nums[0];
            for (int i = 0; i < s; i++)
            {
                int temp = nums[(i + 1) % s];
                nums[(i + 1) % s] = flag;
                flag = temp;
            }
        }
    }
    void rotateII(vector<int> &nums, int k)
    {
        int mod = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + mod);
        reverse(nums.begin() + mod, nums.end());
    }
    void rotateIII(vector<int> &nums, int k)
    {
        int n = nums.size();
        int s = 0;
        for (; k %= n; n -= k, s += k)
        {
            for (int i = 0; i < k; i++)
            {
                swap(nums[s + i], nums[s + n - k + i]);
            }
        }
    }
};
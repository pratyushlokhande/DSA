class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
        {
            return true;
        }

        for (int i = 0; i < flowerbed.size(); i++)
        {
            // print flowerbeed
            // for (int j = 0; j < flowerbed.size(); j++)
            // {
            //     cout << flowerbed[j] << " ";
            // }
            if (flowerbed[i] == 0)
            {
                if (i == 0 and i == flowerbed.size() - 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                else if (i == 0)
                {
                    if (flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else
                {
                    if (flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
            // cout << endl;
            if (n == 0)
            {
                return true;
            }
        }
        return false;
    }
};
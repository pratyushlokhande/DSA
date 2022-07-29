class Solution
{
public:
    set<int> s;

    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        if (s.find(n) != s.end())
            return false;

        s.insert(n);

        int nNum = 0;
        while (n != 0)
        {
            nNum += pow(n % 10, 2);
            n /= 10;
        }

        return isHappy(nNum);
    }
};
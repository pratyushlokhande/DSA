class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int maxDist = INT_MIN;
        int prevSeat = -1;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1 and prevSeat == -1)
            {
                prevSeat = i;
                maxDist = i;
            }
            else if (seats[i] == 1)
            {
                int d = (i - prevSeat) / 2;
                maxDist = max(maxDist, d);
                prevSeat = i;
            }
            else if (i == seats.size() - 1)
            {
                int d = i - prevSeat;
                maxDist = max(maxDist, d);
            }
        }
        return maxDist;
    }
};
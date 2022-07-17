#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    int i = 0;
    uint32_t num = 0;

    while (i < 32)
    {
        uint32_t mask = n & (1 << i);
        num = num | (mask << (31 - i));
        i++;
    }

    return num;
}

void solve()
{
    // code here
    uint32_t n;
    cin >> n;
    cout << reverseBits(n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
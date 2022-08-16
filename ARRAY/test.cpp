#include <bits/stdc++.h>
using namespace std;

// return greatest common divisor of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    // code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> subsequences;

bool isPallindrome(string s, int len)
{
    int l = floor(len / 2);

    for (int i = 0; i < l; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }

    return true;
}

void generateSubsequences(string s, char out[], int idx, int i)
{

    if (s[idx] == '\0')
    {
        out[i] = '\0';
        subsequences.push_back(out);
        return;
    }

    // include first character
    out[i] = s[idx];
    generateSubsequences(s, out, idx + 1, i + 1);

    // exclude
    generateSubsequences(s, out, idx + 1, i);
}

int longestPalindromeSubseq(string s)
{
    char *out = new char[s.length() + 1];

    generateSubsequences(s, out, 0, 0);
    int max_len = 0, len;

    for (auto x : subsequences)
    {
        len = x.length();
        cout << x << endl;
        if (isPallindrome(x, len))
        {
            max_len = max(max_len, len);
        }
    }

    return max_len;
}

// method: 2
int longestPalindromeSubseq2(string s)
{
    int n = s.length();
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    int max_len = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
            max_len = max(max_len, dp[i][j]);
        }
    }
    return max_len;
}

void solve()
{
    // code here
    string s;
    cin >> s;

    cout << longestPalindromeSubseq2(s) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

// take inputs from file
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
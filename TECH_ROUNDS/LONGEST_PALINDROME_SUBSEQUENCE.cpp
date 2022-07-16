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

void solve()
{
    // code here
    string s;
    cin >> s;

    cout << longestPalindromeSubseq(s) << endl;
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
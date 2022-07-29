#include <bits/stdc++.h>
using namespace std;

vector<int> getPattern(string s)
{
    unordered_map<char, int> m;
    vector<int> pat_str(s.length());
    int ctr = 1;
    for (char ch : s)
    {
        if (m.count(ch) == 0)
        {
            m[ch] = ctr;
            ++ctr;
        }
        pat_str.push_back(m[ch]);
    }
    return pat_str;
}

bool checkPatternVector(vector<int> &pat_str, vector<int> &str_str)
{
    for (int i = 0; i < pat_str.size(); ++i)
    {
        if (pat_str[i] != str_str[i])
        {
            return false;
        }
    }
    return true;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> res;
    vector<int> ck_pattern = getPattern(pattern);

    for (string word : words)
    {
        vector<int> ck_word = getPattern(word);
        if (checkPatternVector(ck_pattern, ck_word))
        {
            res.push_back(word);
        }
    }
    return res;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string pattern;
    cin >> pattern;
    vector<string> res = findAndReplacePattern(words, pattern);
    for (string s : res)
    {
        cout << s << " ";
    }
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
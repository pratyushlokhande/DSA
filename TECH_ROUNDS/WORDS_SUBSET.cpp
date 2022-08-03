#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    vector<int> freq(26, 0);

    for (auto x : words2)
    {
        vector<int> temp(26, 0);

        for (auto y : x)
        {
            temp[y - 'a']++;
            freq[y - 'a'] = max(freq[y - 'a'], temp[y - 'a']);
        }
    }

    vector<string> res;

    for (auto x : words1)
    {

        vector<int> temp(26, 0);

        for (auto y : x)
            temp[y - 'a']++;

        bool flag = true;

        for (int i = 0; i < 26; i++)
        {

            if (freq[i] > temp[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
            res.push_back(x);
    }
    return res;
}

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    vector<string> words1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words1[i];
    }
    vector<string> words2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> words2[i];
    }
    vector<string> res = wordSubsets(words1, words2);
    for (auto x : res)
    {
        cout << x << " ";
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
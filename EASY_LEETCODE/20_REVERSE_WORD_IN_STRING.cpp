#include <bits/stdc++.h>
using namespace std;

void reverse(string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

string reverseWords(string s)
{
    stringstream ss(s);
    int counter = 0;
    string word, res;
    while (ss >> word)
    {
        reverse(word);
        res += word;
        counter += (word.size() + 1);
        if (counter < s.size())
        {
            res += " ";
        }
    }
    return res;
}

void solve()
{
    // code here
    string s;
    // read line from stdin
    getline(cin, s);

    cout << reverseWords(s) << endl;
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
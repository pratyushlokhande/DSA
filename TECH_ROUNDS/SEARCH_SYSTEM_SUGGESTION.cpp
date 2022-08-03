#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie
{

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *cur = root;
        for (char c : s)
        {
            if (!cur->children[c - 'a'])
            {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool search(string s)
    {
        TrieNode *cur = root;
        for (char c : s)
        {
            if (!cur->children[c - 'a'])
            {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd;
    }
    bool startsWith(string s)
    {
        TrieNode *cur = root;
        for (char c : s)
        {
            if (!cur->children[c - 'a'])
            {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
}

vector<vector<string>>
suggestedProducts(vector<string> &products, string searchWord)
{
    vector<vector<string>> res;
    Trie t;
    for (string s : products)
    {
        t.insert(s);
    }
    vector<string> cur;
    for (int i = 0; i < searchWord.size(); i++)
    {
        string s = searchWord.substr(0, i + 1);
        if (t.startsWith(s))
        {
            cur.clear();
            for (int j = 0; j < 3; j++)
            {
                string temp = s + products[j];
                if (t.search(temp))
                {
                    cur.push_back(temp);
                }
            }
            if (cur.size() > 0)
            {
                res.push_back(cur);
            }
        }
    }

    return res;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    vector<string> products(n);
    for (int i = 0; i < n; i++)
    {
        cin >> products[i];
    }
    string searchWord;
    cin >> searchWord;
    auto res = suggestedProducts(products, searchWord) << endl;
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
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
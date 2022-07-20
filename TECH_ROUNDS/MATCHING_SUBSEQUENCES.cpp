#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string w)
    {
        Node *temp = root;
        for (int i = 0; i < w.length(); i++)
        {
            if (temp->m.count(w[i]) == 0)
            {
                Node *n = new Node(w[i]);
                temp->m[w[i]] = n;
            }
            temp = temp->m[w[i]];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};

void insertInTrie(string &s, string w, Trie *t, int idx)
{
    if (idx == s.length())
    {
        t->insert(w);
        return;
    }

    // dont keep
    insertInTrie(s, w, t, idx + 1);
    // keep
    string k = w + s[idx];
    insertInTrie(s, k, t, idx + 1);
}

int numMatchingSubseq(string s, vector<string> &words)
{
    string word = "";
    Trie *t = new Trie();

    insertInTrie(s, word, t, 0);
    int res = 0;
    for (auto w : words)
    {
        if (t->search(w))
        {
            res++;
        }
    }
    return res;
}

void solve()
{
    // code here
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cout << numMatchingSubseq(s, words);
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
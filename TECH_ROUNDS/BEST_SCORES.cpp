// Best Score

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    unordered_map<char, Node *> m;
    int count;
    bool isTerminal;
    Node(char d)
    {
        data = d;
        count = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                temp->m[ch] = new Node(ch);
            }
            temp->m[ch]->count += 1;
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    int countPrefixes(string word)
    {
        Node *temp = root;

        int prefCount = 0;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return prefCount + 1;
            }
            prefCount += temp->m[ch]->count;
            temp = temp->m[ch];
        }
        return prefCount;
    }
};

int main()
{
    string words[] = {"aab", "aac"};
    Trie t;
    for (string word : words)
    {
        t.insert(word);
    }

    int ans = 0;

    for (string word : words)
    {
        ans += t.countPrefixes(word);
    }

    cout << "RESULT => " << ans << endl;
    return 0;
}

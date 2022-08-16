#include <bits/stdc++.h>
using namespace std;

// LRU Cache
class LRUCache
{
    unordered_map<int, pair<int, int>> m;
    list<int> l;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (m.count(key) == 0)
            return -1;
        l.push_front(key);
        return m[key].second;
    }

    void put(int key, int value)
    {
        if (m.count(key) == 0)
        {
            if (m.size() == capacity)
            {
                int last = l.back();
                l.pop_back();
                m.erase(last);
            }
            l.push_front(key);
        }
        else
        {
            l.remove(key);
            l.push_front(key);
        }
        m[key] = make_pair(value, key);
    }
};

void solve()
{
    // code here
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
#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int pos;

    Meeting(int s, int e, int p)
    {
        start = s;
        end = e;
        pos = p;
    }
};

// class Compare
// {
// public:
//     bool operator()(const Meeting *p, const Meeting *q)
//     {
//         if (p.end > q.end)
//         {
//             return true;
//         }
//         else if (p.end == q.end)
//         {
//             return p.pos < q.pos;
//         }

//         return false;
//     }
// };

bool compare(Meeting *p, Meeting *q)
{
    if (p->end < q->end)
    {
        return true;
    }
    else if (p->end == q->end)
    {
        return p->pos < q->pos;
    }
    return false;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<Meeting *> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i] = new Meeting(start[i], end[i], i);
    }

    sort(v.begin(), v.end(), compare);

    // for (auto x : v)
    // {
    //     cout << x->start << " " << x->end << " " << x->pos << endl;
    // }

    int ans = 1;
    auto it = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i]->start > it->end)
        {
            ans++;
            it = v[i];
        }
    }
    return ans;
}

void solve()
{
    // code here
    int n;
    cin >> n;
    int start[n];
    int end[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    cout << maxMeetings(start, end, n) << endl;
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
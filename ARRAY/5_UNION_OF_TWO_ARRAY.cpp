#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code here
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int aux[n + m] = {0};
    int idxA = 0;
    int idxB = 0;

    if (a[idxA] < b[idxB])
    {
        aux[idxA] = a[idxA];
        idxA++;
    }
    else
    {
        aux[idxB] = b[idxB];
        idxB++;
    }

    int prev = aux[0];
    int auxIdx = 1;

    while (idxA < n || idxB < m)
    {
        if (idxA < n && idxB < m)
        {
            if (a[idxA] < b[idxB])
            {
                if (a[idxA] != prev)
                {
                    aux[auxIdx] = a[idxA];
                    prev = a[idxA];
                    auxIdx++;
                }
                idxA++;
            }
            else
            {
                if (b[idxB] != prev)
                {
                    aux[auxIdx] = b[idxB];
                    prev = b[idxB];
                    auxIdx++;
                }
                idxB++;
            }
        }
        else if (idxA < n)
        {
            if (a[idxA] != prev)
            {
                aux[auxIdx] = a[idxA];
                prev = a[idxA];
                auxIdx++;
            }
            idxA++;
        }
        else
        {
            if (b[idxB] != prev)
            {
                aux[auxIdx] = b[idxB];
                prev = b[idxB];
                auxIdx++;
            }
            idxB++;
        }
    }

    for (int i = 0; i < n + m; i++)
        cout << aux[i] << " ";

    cout << endl;
    cout << "result: " << auxIdx << endl;
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
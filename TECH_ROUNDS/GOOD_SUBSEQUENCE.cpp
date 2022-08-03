#include <bits/stdc++.h>
using namespace std;

// maximum possible length of good subseuence with differec=nce of consecutive element is greater than D
// int getLengthOfLongestPossibleGoodSequence(vector<int> &arr, int D)
// {
//     // return max possible subsequence length with consicutive difference greater than D
//     int n = arr.size();
//     int dp[n];
//     dp[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if (abs(arr[i] - arr[j]) >= D)
//             {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     return *max_element(dp, dp + n);
// }

// int longestGoodSubsequence(vector<int> &arr, int D)
// {
//     // longest good subsequence with (i+1, i) difference >= D
//     int n = arr.size();
//     vector<int> dp(n, 1);
//     for (int i = 1; i < n; i++)
//     {
//         if (abs(arr[i] - arr[i - 1]) >= D)
//         {
//             dp[i] = dp[i - 1] + 1;
//         }
//     }
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans = max(ans, dp[i]);
//     }
//     return ans;
// }

// // A subsequence of length k of A is called good if for every j from 2 to k follow condition |A[j] - A[j-1]| >= D
// // Find the length of longest good subsequence  in A
// int getLongestGoodSubsequenceOfLength(vector<int> &arr, int D)
// {
//     int n = arr.size();
//     int dp[n];
//     dp[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//         {
//             if (abs(arr[i] - arr[j]) >= D)
//             {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }
//     return *max_element(dp, dp + n);
// }

void addOneToAllElements(vector<int> &arr, int s, int e)
{
    for (int i = s; i < e; i++)
    {
        arr[i]++;
    }
}

void subtractOneFromAllElements(vector<int> &arr, int s, int e)
{
    for (int i = s; i < e; i++)
    {
        arr[i]--;
    }
}

int smallest_element_index(vector<int> &arr, int n)
{
    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

int helper(int n, int m, int k, vector<int> arr)
{
    // cout << "n: " << n << " m: " << m << " k: " << k << endl;
    // print array
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl
    //      << endl;
    if (m == 0)
    {
        return arr[smallest_element_index(arr, n)];
    }

    int ans = INT_MAX;
    int it = smallest_element_index(arr, n);
    int s = max(it - k + 1, 0);
    int e = min(n, it + k);
    // cout << "s : " << (it - k + 1) << " e : " << (it + k) << endl;
    for (int i = s; i < e and (i + k) <= n; i++)
    {
        addOneToAllElements(arr, i, i + k);
        ans = min(ans, helper(n, m - 1, k, arr));
        subtractOneFromAllElements(arr, i, i + k);
    }
    return ans;
}

// get minimum element of array after adding 1 to k continuous element m times
int getMinElement(int n, int m, int k, vector<int> &arr)
{
    if (n == k)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] += m * 1;
        }

        return *min_element(arr.begin(), arr.end());
    }
    return helper(n, m, k, arr);
}

void solve()
{
    // code here
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getMinElement(n, m, k, arr) << endl;
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

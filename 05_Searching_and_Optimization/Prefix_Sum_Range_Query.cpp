// Topic: Optimization Algorithms
// Problem: Calculate sum of a range [L, R] for multiple queries.
// Strategy: Prefix Sum Technique.
// Optimization: 
//   - Brute Force: O(N * Q) -> TLE (Time Limit Exceeded)
//   - Prefix Sum: O(N) Pre-processing + O(1) per Query -> Efficient.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    // Using 1-based indexing for convenience
    vector<long long int> v(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // Pre-calculate Prefix Sum array
    vector<long long int> pre(n + 1);
    pre[1] = v[1];

    for(int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i]; // Cumulative Sum
    }

    // Answer queries in O(1)
    while(q--)
    {
        int l, r;
        cin >> l >> r;

        if(l == 1)
        {
            cout << pre[r] << endl;
        }
        else
        {
            // Formula: Sum(L, R) = Pre[R] - Pre[L-1]
            cout << pre[r] - pre[l - 1] << endl;
        }
    }
    return 0;
}
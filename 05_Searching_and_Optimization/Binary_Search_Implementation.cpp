// Topic: Search Algorithms
// Problem: Check if a number exists in an array for multiple queries.
// Strategy: Binary Search (Divide and Conquer).
// Requirement: The array must be sorted first.
// Complexity: 
//   - Sorting: O(N log N)
//   - Searching: O(log N) per query.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sorting is mandatory for Binary Search
    sort(a, a + n);

    while(q--)
    {
        int x;
        cin >> x; // Target value

        int flag = 0;
        int l = 0;
        int r = n - 1;

        // Binary Search Logic
        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(a[mid] == x)
            {
                flag = 1;
                break;
            }
            else if(a[mid] > x)
            {
                r = mid - 1; // Discard right half
            }
            else
            {
                l = mid + 1; // Discard left half
            }
        }

        if(flag == 0)
        {
            cout << "not found" << endl;
        }
        else
        {
            cout << "found" << endl;
        }
    }
    return 0;
}
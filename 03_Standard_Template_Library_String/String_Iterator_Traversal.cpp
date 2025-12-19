// Topic: STL Iterators
// Problem: Traverse a container (String) using Iterators instead of indices.
// Logic: Using .begin() pointer and incrementing until .end().
// Note: Iterators are the standard way to traverse complex data structures (like Linked Lists or Sets) where numeric indexing [i] is not possible.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Hello";

    // Using 'auto' for type inference (automatically detects string::iterator)
    for(auto it = s.begin(); it < s.end(); it++)
    {
        cout << *it << endl; // Dereference iterator to access value
    }

    return 0;
}
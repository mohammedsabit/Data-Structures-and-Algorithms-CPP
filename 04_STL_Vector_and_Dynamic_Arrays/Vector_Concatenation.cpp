// Topic: Vector Manipulation
// Problem: Concatenate two vectors (v2 followed by v1) into a new vector.
// Complexity: O(N) - Linear time required to copy elements.

#include<bits/stdc++.h>
using namespace std;

void concat(int n, vector<int> v1, vector<int> v2)
{
    // Initialize v3 with total size to avoid reallocation during insertion
    vector<int> v3(n + n);            

    // Copy v2 first
    for(int i = 0; i < n; i++)          
    {
        v3[i] = v2[i];
    }

    // Copy v1 second (offset by n)
    for(int i = n; i < v3.size(); i++)   
    {
        v3[i] = v1[i - n];
    }

    // Print result
    for(int i = 0; i < v3.size(); i++)   
    {
        cout << v3[i] << " "; 
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v1(n);              
    for(int i = 0; i < n; i++)          
    {
        cin >> v1[i];
    }

    vector<int> v2(n);              
    for(int i = 0; i < n; i++)          
    {
        cin >> v2[i];
    }

    concat(n, v1, v2);
    return 0;
}
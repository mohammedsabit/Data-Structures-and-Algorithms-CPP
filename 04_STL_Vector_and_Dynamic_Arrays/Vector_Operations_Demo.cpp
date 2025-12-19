// Topic: STL Vector
// Problem: Demonstrate core vector operations: Insert, Delete, Resize, and Search.
// Logic: Using built-in STL functions (insert, erase, replace, find).
// Advantage: Vectors handle memory management automatically, unlike static arrays.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Initialization with initializer list
    vector<int> v = {1, 2, 3, 2, 5};
    vector<int> v2;
    
    // Copying vectors
    v2.assign(v.begin(), v.end());

    // Modifying size at the end
    v.push_back(10);        
    v.pop_back();           

    // Insertion O(N) - Elements shift right
    v.insert(v.begin() + 3, 100);

    // Inserting multiple elements
    v.insert(v.begin() + 4, {200, 300, 400});   

    // Deletion O(N) - Elements shift left
    v.erase(v.begin() + 4);           
    v.erase(v.begin() + 3, v.begin() + 6);   

    // Batch replacement
    replace(v.begin(), v.end(), 2, 100);

    // Traversal
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Searching using Iterator
    auto it = find(v.begin(), v.end(), 5);

    if(it == v.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    return 0;
}
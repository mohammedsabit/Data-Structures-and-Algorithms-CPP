// Topic: Stack vs Heap Memory
// Problem: Return an array from a function.
// Logic: Using 'new' allocates memory in Heap, which persists after the function returns.
// (Stack memory would be destroyed when the function ends).

#include<bits/stdc++.h>
using namespace std;

int* get_array()
{
    // Allocation in Heap
    int* arr = new int[5];   
    for(int i=0; i<5; i++)
    {
        cin >> arr[i];
    }
    return arr;   // Returning the pointer (address) of the heap memory
}

int main()
{
    int* ptr = get_array();
    
    for(int i=0; i<5; i++)
    {
        cout << ptr[i] << " ";
    }
    
    // Delete memory when done
    delete[] ptr;
    return 0;
}
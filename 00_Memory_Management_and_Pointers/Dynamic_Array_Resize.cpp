// Topic: Dynamic Memory Management
// Problem: Manually increase the size of an array at runtime.
// Logic: Create a larger array in Heap, copy old elements, delete old memory.
// Note: This implementation demonstrates how vectors work internally.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Allocate memory for 3 integers in Heap
    int* arr = new int[3];   
    for(int i=0; i<3; i++)
    {
        cin >> arr[i];
    }

    // Allocate new larger memory block
    int* temp_arr = new int[5];   

    // Copy elements from old array to new array
    for(int i=0; i<3; i++)  
    {
        temp_arr[i] = arr[i];
    }

    // Deallocate old memory to prevent Memory Leak
    delete[] arr;  

    // Add new elements
    temp_arr[3] = 40;
    temp_arr[4] = 50;

    // Output the resized array
    for(int i=0; i<5; i++)
    {
        cout << temp_arr[i] << " ";   
    }
    return 0;
}
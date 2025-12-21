// Topic: Singly Linked List (SLL)
// Problem: Create Linked List Nodes using Dynamic Memory Allocation.
// Logic: Using 'new' keyword to allocate nodes in Heap memory. 
// Why Dynamic? Unlike arrays, SLL nodes are non-contiguous and must be manually linked.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    
    // Constructor to initialize value and null pointer
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    // Allocating nodes in Heap Memory
    Node* head = new Node(10);
    Node* a = new Node(20);

    // Linking the nodes (Head -> A)
    head->next = a;

    // Accessing values using arrow operator (->)
    cout << "Head Value: " << head->val << endl;
    cout << "Next Value: " << head->next->val << endl;
    
    return 0;
}
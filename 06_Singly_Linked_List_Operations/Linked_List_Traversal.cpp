// Topic: Linked List Algorithms
// Problem: Traverse and print all elements of a Singly Linked List.
// Logic: Using a temporary pointer to iterate through the list until NULL is reached.
// Complexity: O(N) - Linear Time.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    // 1. Initialize Nodes
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(450);

    // 2. Link Nodes
    head->next = a;
    a->next = b;
    b->next = c;

    // 3. Traversal Logic
    // Using a temporary pointer 'temp' to traverse, ensuring the 'head' reference is preserved.
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next; // Move to next node
    }
    
    return 0;
}
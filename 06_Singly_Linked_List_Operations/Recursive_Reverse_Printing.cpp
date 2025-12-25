// Topic: Recursion & Stack Memory
// Problem: Print a Linked List in Reverse order without reversing the links.
// Logic: Utilizing the system's "Call Stack".
// The print statement is placed AFTER the recursive call, so it executes 
// during the "return" (unwinding) phase of recursion.

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

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
}

void print_reverse_linked_list(Node* temp)
{
    // Base condition: Stop when we reach end of list
    if(temp == NULL)
    {
        return;
    }
    
    // Recursive Call: Go to the next node first
    print_reverse_linked_list(temp->next);
    
    // Print logic executes when returning (Backtracking)
    cout << temp->val << " ";
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    
    print_reverse_linked_list(head);
    return 0;
}
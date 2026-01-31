// Topic: DLL Operations
// Problem: Insert a node at a specific index in a Doubly Linked List.
// Logic: Traverse to (index-1), then update the next/prev links of the surrounding nodes 
// to include the new node.

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node* prev;
    
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_any_pos(Node* head, int idx, int val)
{
    Node* newnode = new Node(val);
    Node* temp = head;

    // Traverse to the node before the insertion point
    for(int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }

    // Update pointers to incorporate newnode
    newnode->next = temp->next;
    temp->next->prev = newnode;

    temp->next = newnode;
    newnode->prev = temp;
}

void print_forward(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    // Inserting values at specified indices
    insert_at_any_pos(head, 2, 100);
    insert_at_any_pos(head, 1, 200);
    
    print_forward(head);
    return 0;
}
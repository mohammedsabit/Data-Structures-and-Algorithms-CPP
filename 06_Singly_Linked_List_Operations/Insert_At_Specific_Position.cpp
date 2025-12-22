// Topic: Pointer Manipulation
// Problem: Insert a node at a specific index (Body of the list).
// Logic: Traverse to index-1, then link NewNode to Next, and Previous to NewNode.
// Complexity: O(N) worst case (traversing to the end).

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

void insert_at_any_pos(Node* &head, int idx, int val)
{
    Node* newnode = new Node(val);
    Node* temp = head;

    // Traverse to the node BEFORE the target index
    for(int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    // Important: Link newnode to the rest of the list FIRST
    newnode->next = temp->next;
    
    // Then link the previous node to newnode
    temp->next = newnode;
}

void print_linked_list(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    head->next = a;
    a->next = b;

    insert_at_any_pos(head, 2, 100); // Insert at index 2 
    
    print_linked_list(head);
    return 0;
}
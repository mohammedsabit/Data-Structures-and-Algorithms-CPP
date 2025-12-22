// Topic: Singly Linked List (SLL)
// Problem: Insert a node at the tail (end) of the list efficiently.
// Optimization: Using a 'tail' pointer allows O(1) insertion time, 
// avoiding the O(N) traversal required if we only had a 'head' pointer.

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

// Optimized Insertion Logic
// Passing head and tail by reference (&) to modify original pointers
void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);

    // Case 1: List is empty
    if(head == NULL)
    {
        head = newnode;
        tail = newnode; // Head and Tail are the same
        return;
    }
    
    // Case 2: List is not empty
    tail->next = newnode; // Link current tail to new node
    tail = tail->next;    // Update tail pointer to the new last node
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
    // Initial State
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->next = tail;

    // Performing O(1) Insertions
    insert_at_tail(head, tail, 40);
    insert_at_tail(head, tail, 50);
    insert_at_tail(head, tail, 60);
    insert_at_tail(head, tail, 70);

    print_linked_list(head);
    cout << "Tail: " << tail->val << endl;
    
    return 0;
}
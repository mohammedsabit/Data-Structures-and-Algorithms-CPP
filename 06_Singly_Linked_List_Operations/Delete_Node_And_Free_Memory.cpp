// Topic: Memory Management & Pointers
// Problem: Delete a node at a specific position and free its memory.
// Engineering Principle: Preventing Memory Leaks.
// Logic:
// 1. Traverse to the node BEFORE the target.
// 2. Unlink the target node.
// 3. Explicitly deallocate memory using 'delete'.

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
        return; // Added return for safety
    }
    tail->next = newnode;
    tail = tail->next;
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

void delete_at_any_pos(Node* &head, Node* &tail, int idx)
{
    Node* temp = head;
    
    // Case 1: Deleting the Head
    if(idx == 0)
    {
        Node* deletenode = head;
        head = head->next;
        delete deletenode; // Critical: Freeing memory
        return;
    }

    // Case 2: Deleting from Body/Tail
    for(int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }

    Node* deletenode = temp->next;
    temp->next = deletenode->next;
    
    delete deletenode; // Critical: Freeing memory
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

    // Delete node at index 2
    delete_at_any_pos(head, tail, 2);
    
    print_linked_list(head);
    return 0;
}
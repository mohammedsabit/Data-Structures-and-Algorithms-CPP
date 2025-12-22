// Topic: Linked List Logic (Interview Question)
// Problem: Find the middle element(s) of a Singly Linked List.
// Approach: Size Calculation Method.
// 1. Traverse to count total nodes (N).
// 2. Traverse again N/2 times to reach the middle.

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

void middle_element(Node* head)
{
    Node* temp = head;
    int count = 0;

    // Step 1: Calculate total size
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Step 2: Traverse to the middle
    temp = head;
    
    // Case: Odd number of elements (1 middle)
    if(count % 2 != 0)
    {
        for(int i = 1; i <= count / 2; i++)
        {
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
    // Case: Even number of elements (2 middles)
    else
    {
        for(int i = 1; i < count / 2; i++)
        {
            temp = temp->next;
        }
        // Printing the two middle values
        cout << temp->val << " " << temp->next->val;
    }
}

int main()
{
    // Creating a list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* tail = new Node(6);

    head->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = tail;
    
    middle_element(head);
    return 0;
}
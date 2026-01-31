// Topic: System Logic & Error Handling
// Problem: Process multiple insertion queries in a DLL with index validation.
// Logic:
// 1. Validate index (Check if x < 0 or x > current size).
// 2. Route insertion to correct logic (Head, Tail, or Middle).
// 3. Print list in both directions for verification.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int current_sz = 0;

void process_insertion(Node *&head, Node *&tail, int idx, int val)
{
    // Case 1: Insert at Head
    if (idx == 0)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    // Case 2: Insert at Tail
    else if (idx == current_sz)
    {
        Node *newnode = new Node(val);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    // Case 3: Insert at Middle
    else
    {
        Node *newnode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }
    current_sz++;
}

void print_forward(Node *head)
{
    Node *temp = head;
    cout << "L -> ";
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_backward(Node* tail)
{
    Node* temp = tail;
    cout << "R -> ";
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int total_queries;
    cin >> total_queries;

    while (total_queries--)
    {
        int index, value;
        cin >> index >> value;

        // Validation Logic
        if (index < 0 || index > current_sz)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            process_insertion(head, tail, index, value);
            print_forward(head);
            print_backward(tail);
        }
    }
    return 0;
}
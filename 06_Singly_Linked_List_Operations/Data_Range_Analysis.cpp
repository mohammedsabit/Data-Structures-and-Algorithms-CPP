// Topic: Statistical Analysis on Data Structures
// Problem: Calculate the Range (Max Value - Min Value) of data stored in a Linked List.
// Logic: Single pass traversal (O(N)) to identify extrema.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }
}

int max_value(Node* &head)
{
    int max_val = INT_MIN;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->val > max_val)
        {
            max_val = temp->val;
        }
        temp = temp->next;
    }
    return max_val;
}

int min_value(Node* &head)
{
    int min_val = INT_MAX;
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->val < min_val)
        {
            min_val = temp->val;
        }
        temp = temp->next;
    }
    return min_val;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    
    // Calculate Range
    int max_val = max_value(head);
    int min_val = min_value(head);
    
    cout << max_val - min_val << endl;
    return 0;
}
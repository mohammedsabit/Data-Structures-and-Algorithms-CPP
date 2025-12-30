// Topic: Data Integrity / Hashing
// Problem: Construct a Linked List containing only unique values from input.
// Strategy: Space-Time Tradeoff.
// We use a Frequency Array (Hashing) to check for duplicates in O(1) time 
// before insertion, ensuring the list remains unique during construction.

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
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }
}

void print_linked_list(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    // Frequency array to track duplicates (Assumed max value 1005)
    int freq[1005] = {0}; 

    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        
        // Filter: Only insert if value hasn't appeared yet
        if(freq[val] == 0)
        {
            freq[val]++;
            insert_at_tail(head, tail, val);
        }
    }
    print_linked_list(head);
    return 0;
}
// Topic: Optimization Algorithms
// Problem: Reverse a Doubly Linked List using the Two-Pointer technique.
// Logic: Simultaneously move pointers from Head and Tail towards the center, 
// swapping values at each step.
// Complexity: O(N) Time.

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

int list_size = 0;

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    list_size++;
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = tail->next;
}

void reverse_list_values(Node* head, Node* tail, int sz)
{
    Node* left = head;
    Node* right = tail;

    int i = 0, j = sz - 1;

    // Value swapping logic
    while(i < j)
    {
        swap(left->val, right->val);
        left = left->next;
        right = right->prev;
        i++;
        j--;
    }
}

void print_list(Node* head)
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
    while(cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    
    reverse_list_values(head, tail, list_size);
    print_list(head);
    
    return 0;
}
// Topic: System Design & Data Structures
// Problem: Perform dynamic operations (Insert Head/Tail, Delete) based on Query inputs.
// Logic: 
// 1. Parse Query Type (0 = Head, 1 = Tail, 2 = Delete).
// 2. Validate Index using Size calculation.
// 3. Handle Edge Cases (Deleting Head vs Tail vs Body).

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

// O(1) Insertion at Head
void insert_at_head(Node* &head, Node* &tail, int v)
{
    Node* newnode = new Node(v);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

// O(1) Insertion at Tail
void insert_at_tail(Node* &head, Node* &tail, int v)
{
    Node* newnode = new Node(v);
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

void delete_at_head(Node* &head)
{
    Node* deletenode = head;
    head = deletenode->next;
    delete deletenode; // Prevent Memory Leak
}

void delete_at_any_pos(Node* &head, int v)
{
    Node* temp = head;
    // Traverse to the node BEFORE the target
    for(int i = 0; i < v - 1; i++)
    {
        temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = deletenode->next;
    delete deletenode; 
}

void delete_at_tail(Node* &head, Node* &tail, int v)
{
    Node* temp = head;
    // Traverse to second last node
    for(int i = 0; i < v - 1; i++)
    {
        temp = temp->next;
    }
    Node* deletenode = temp->next;
    temp->next = deletenode->next;
    delete deletenode;
    tail = temp; // Update Tail pointer
}

int size_of_linked_list(Node* &head)
{
    Node* temp = head;
    int size = 0;
    while(temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

void print_linked_list(Node* head)
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

    int q;
    cin >> q; // Number of Queries

    while(q--)
    {
        int x, v;
        cin >> x >> v; // Operation Code, Value

        if(x == 0) // Insert Head
        {
            insert_at_head(head, tail, v);
            print_linked_list(head);
            cout << endl;
        }
        else if(x == 1) // Insert Tail
        {
            insert_at_tail(head, tail, v);
            print_linked_list(head);
            cout << endl;
        }
        else if(x == 2) // Delete
        {
            int sz = size_of_linked_list(head);

            if(v >= sz) // Invalid Index check
            {
                print_linked_list(head);
                cout << endl;
            }
            else
            {
                if(v == 0)
                {
                    delete_at_head(head);
                    print_linked_list(head);
                    cout << endl;
                }
                else if(v == sz - 1)
                {
                    delete_at_tail(head, tail, v);
                    print_linked_list(head);
                    cout << endl;
                }
                else
                {
                    delete_at_any_pos(head, v);
                    print_linked_list(head);
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
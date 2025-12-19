// Topic: Dynamic Objects & Pointers
// Problem: Create an object inside a function and use it in main().
// Logic: Allocate object in Heap memory and return the pointer. 
// This concept is fundamental for building Linked List Nodes.

#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int cls;
    int roll;
    double gpa;

    Student(int cls, int roll, double gpa)    
    {
        // 'this' pointer resolves naming conflict between parameter and property
        this->cls = cls;
        this->roll = roll;
        this->gpa = gpa;
    }
};

Student* create_student()
{
    // Dynamic object creation
    Student* student_ptr = new Student(10, 18, 4.67);  
    return student_ptr;   
}

int main()
{
    Student* p = create_student();
    
    // Accessing properties using arrow operator (->) for pointers
    cout << p->cls << " " << p->roll << " " << p->gpa << endl;  
    
    delete p; // Free memory
    return 0;
}
// Topic: Object-Oriented Programming (OOP)
// Problem: Initialize object properties using a Constructor.
// Logic: A constructor ensures an object is created with valid data immediately.

#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    int cls;
    int roll;
    double gpa;

    // Parameterized Constructor
    Student(int c, int r, double g)    
    {
        cls = c;
        roll = r;
        gpa = g;
    }
};

int main()
{
    // Initialize object 'rahim' directly
    Student rahim(10, 18, 4.67);

    cout << rahim.cls << " " << rahim.roll << " " << rahim.gpa << endl;
    return 0;
}
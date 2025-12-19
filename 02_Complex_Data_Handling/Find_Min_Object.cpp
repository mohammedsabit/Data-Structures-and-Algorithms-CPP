// Topic: Data Search
// Problem: Find the Student with the minimum marks in a dataset.
// Logic: Linear Scan (O(N)) keeping track of the object with the lowest value found so far.

#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll;
    int marks;
};

int main()
{
    int n;
    cin >> n;

    Student students[n];

    for(int i=0; i<n; i++)
    {
        cin >> students[i].name >> students[i].roll >> students[i].marks;
    }

    // Initialize minimum object with maximum possible marks
    Student min_student;
    min_student.marks = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(students[i].marks < min_student.marks)
        {
            min_student = students[i]; // Update the entire object
        }
    }

    cout << min_student.name << " " << min_student.roll << " " << min_student.marks;
    return 0;
}
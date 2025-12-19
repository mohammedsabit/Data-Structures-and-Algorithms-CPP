// Topic: Custom Sorting
// Problem: Sort an array of Students based on Marks (Descending), then Roll (Ascending).
// Logic: Implementing a custom Comparator function (cmp) for std::sort.

#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll;
    int marks;
};

// Custom Comparator
bool compareStudents(Student l, Student r)
{
    // If marks are equal, sort by Roll number (Ascending)
    if(l.marks == r.marks)
    {
        return l.roll < r.roll;
    }
    // Otherwise, sort by Marks (Descending)
    else
    {
        return l.marks > r.marks;
    }
}

int main()
{
    int n;
    cin >> n;
    Student students[n];
    
    for(int i=0; i<n; i++)
    {
        cin >> students[i].name >> students[i].roll >> students[i].marks;
    }

    // Sort using custom logic
    sort(students, students + n, compareStudents);

    for(int i=0; i<n; i++)
    {
        cout << students[i].name << " " << students[i].roll << " " << students[i].marks << endl;;
    }
    return 0;
}
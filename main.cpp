
#include <bits/stdc++.h>
using namespace std;
struct Student
{
    string name;
    int rollNumber;
    double marks;
    Student(string n, int roll, double m) : name(n), rollNumber(roll), marks(m) {}
};
double calculateAverage(const vector<Student> &students)
{
    if (students.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (const auto &student : students)
    {
        sum += student.marks;
    }
    return sum / students.size();
}
void displayStudent(const Student &student)
{
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Marks: " << student.marks << endl;
    cout << "-------------------------------------" << endl;
}
void addStudent(vector<Student> &students)
{
    string name;
    int rollNumber;
    double marks;
    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;
    cout << "Enter marks: ";
    cin >> marks;
    students.emplace_back(name, rollNumber, marks);
    cout << "Student added successfully!" << endl;
}
void deleteStudent(vector<Student> &students, int rollNumber)
{
    auto it = find_if(students.begin(), students.end(), [rollNumber](const Student &s)
                      { return s.rollNumber == rollNumber; });
    if (it != students.end())
    {
        students.erase(it);
        cout << "Student with roll number " << rollNumber << " deleted successfully!" << endl;
    }
    else
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}
void updateStudent(vector<Student> &students, int rollNumber)
{
    auto it = find_if(students.begin(), students.end(), [rollNumber](const Student &s)
                      { return s.rollNumber == rollNumber; });
    if (it != students.end())
    {
        cout << "Enter new name: ";
        getline(cin >> ws, it->name);
        cout << "Enter new marks: ";
        cin >> it->marks;
        cout << "Student details updated successfully!" << endl;
    }
    else
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}
void searchStudent(const vector<Student> &students, int rollNumber)
{
    auto it = find_if(students.begin(), students.end(), [rollNumber](const Student &s)
                      { return s.rollNumber == rollNumber; });
    if (it != students.end())
    {
        displayStudent(*it);
    }
    else
    {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }
}
void displayAllStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No students in the system." << endl;
        return;
    }
    cout << "List of all students:" << endl;
    for (const auto &student : students)
    {
        displayStudent(student);
    }
}
int main()
{
    vector<Student> students;
    int choice;
    int rollNumber;
    while (true)
    {
        cout << "\nStudent Management System Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Calculate Average Marks" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin.ignore();
            addStudent(students);
            break;
        case 2:
            cout << "Enter roll number of student to delete: ";
            cin >> rollNumber;
            deleteStudent(students, rollNumber);
            break;
        case 3:
            cout << "Enter roll number of student to update: ";
            cin >> rollNumber;
            updateStudent(students, rollNumber);
            break;
        case 4:
            cout << "Enter roll number of student to search: ";
            cin >> rollNumber;
            searchStudent(students, rollNumber);
            break;
        case 5:
            displayAllStudents(students);
            break;
        case 6:
            cout << fixed << setprecision(2);
            cout << "Average marks of all students: " << calculateAverage(students) << endl;
            break;
        case 7:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}
GULZAR GROUP OF INSTITUTES
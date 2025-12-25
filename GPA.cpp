#include <iostream>
#include <iomanip>

using namespace std;

struct student_record{
    string name;
    float gpa;
    char grade[7];
    string school;
    bool enrolled;
};

int gpa_calc(char grade) {
    switch(grade){
        case 'A':
            return(4);
        case 'B':
            return(3);
        case 'C':
            return(2);
        case 'D':
            return(1);
        case 'F':
            return(0);
        default:
            return(0);
    }
}

int main(){

    student_record student;
    cout << "Enter Name: ";
    cin >> student.name;
    cout << endl;

    float total = 0;
    
    for (int i = 0; i < 7; i++){
        char temp;
        cout << "Enter grade for subject #" << i + 1 << ": ";
        cin >> temp;
        student.grade[i] = temp;
        total = total + gpa_calc(temp);
    }

    student.gpa = total / 7;
    
    cout << "School Name: ";
    cin >> student.school;

    cout << "Are you enrolled: ";
    cin >> student.enrolled;

    cout << endl << "Student Name: " << student.name << endl;
    cout << "GPA: " << fixed << setprecision(2) << student.gpa << endl;
    cout << "School: " << student.school << endl;
    cout << "Enrolled: " << (student.enrolled ? "Yes" : "No") << endl;

    return 0;
}
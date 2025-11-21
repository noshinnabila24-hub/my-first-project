
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<Student> students = {
        {"Amina", 85},
        {"Karim", 92},
        {"Rahim", 85},
        {"Tania", 95},
        {"Arif", 92},
        {"babu", 85}
    };


    cout << "Before sorting:\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << students[i].marks << "\n";
    }


    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.marks != b.marks)
            return a.marks > b.marks;
        return a.name < b.name;
    });


    cout << "\nAfter sorting:\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << students[i].marks << "\n";
    }

    return 0;
}


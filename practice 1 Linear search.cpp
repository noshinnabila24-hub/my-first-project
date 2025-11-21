#include <iostream>
#include <vector>
#include <string>
using namespace std;

int linearSearch(vector<string> arr, string key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {

    vector<string> employees = {"Alo", "Roton", "Charli", "Dia", "Sujon"};

    string name;
    cout << "Enter employee name: ";
    getline(cin, name);

    int pos = linearSearch(employees, name);

    if (pos != -1) {
        cout << name << " is found at position " << pos << endl;
    } else {
        cout << name << " not found in the list" << endl;
    }

    return 0;
}


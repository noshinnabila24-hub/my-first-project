#include <iostream>
using namespace std;


void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayList(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    string students[] = {"Nodi", "Arif", "Zara", "Rahim", "Sabbir"};
    int n = 5;

    cout << "Before sorting:\n";
    displayList(students, n);

    quickSort(students, 0, n - 1);

    cout << "After sorting:\n";
    displayList(students, n);

    return 0;
}


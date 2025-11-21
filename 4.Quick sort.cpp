#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int left = low;
    int right = high;
    int mid = arr[(low + high) / 2];

    while (left <= right) {
        while (arr[left] < mid) left++;
        while (arr[right] > mid) right--;

        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    quickSort(arr, low, right);
    quickSort(arr, left, high);
}

int main() {
    int arr[] = {50, 23, 9, 18, 61, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}


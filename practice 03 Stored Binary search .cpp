#include <iostream>
using namespace std;

int binarySearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int products[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(products) / sizeof(products[0]);
    int id;
    cout << "Enter product ID to search: ";
    cin >> id;
    int index = binarySearch(products, n, id);
    if (index != -1)
        cout << "Product  found at index " << index << endl;
    else
        cout << "Product  is not in the inventory" << endl;
    return 0;
}


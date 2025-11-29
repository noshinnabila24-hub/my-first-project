#include <iostream>
using namespace std;

int main() {
    int arr1[5] = {2, 3, 4, 5, 6};
    int arr2[3] = {6, 7, 8};
    int n1 = 5, n2 = 3;
    int merged[n1 + n2];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }


    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    cout << "Merged Sorted Array: ";
    for (int x = 0; x < n1 + n2; x++) {
        cout << merged[x] << " ";
    }

    return 0;
}


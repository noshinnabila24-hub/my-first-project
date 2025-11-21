#include <iostream>
using namespace std;


int recursiveSum(int arr[], int n) {
    if (n <= 0)
        return 0;

    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int total = recursiveSum(arr, n);
    cout << "Sum of array elements = " << total << endl;
    return 0;
}


#include <iostream.h>

int main() {
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;
    int price;

    cout << "Enter new product price: ";
    cin >> price;


    int i = n - 1;
    while (i >= 0 && arr[i] > price) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = price;
    n++;

    cout << "Updated sorted prices: ";
    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    cout << "\n";

    return 0;
}


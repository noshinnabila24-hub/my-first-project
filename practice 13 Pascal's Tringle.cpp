#include <iostream>
using namespace std;

int pascal(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int space = 0; space < n - i; space++)
            cout << "  ";


        for (int j = 0; j <= i; j++)
            cout << pascal(i, j) << "   ";

        cout << "\n";
    }
    return 0;
}


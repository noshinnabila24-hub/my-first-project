#include<iostream>

using namespace std;
int main() {
    int arr[10] = {2, 4, 7, 11, 15, 20};
    int n = 6;
    int budget;

    cout << "Enter budget: ";
    cin >> budget;

    int left = 0, right = n - 1;
    int found = 0;

    while (left < right && found == 0) {
        int sum = arr[left] + arr[right];

        if (sum == budget) {
            cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << budget << "\n";
            found = 1;
        }
        else if (sum < budget) {
            left++;
        }
        else {
            right--;
        }
    }

    if (found == 0) {
        cout << "No such pair exists.\n";
    }

    return 0;
}


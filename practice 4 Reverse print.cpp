#include <iostream>
#include <vector>
using namespace std;


void reversePrint(vector<int>& arr, int index) {
    if (index < 0) return;
    cout << arr[index] << " ";
    reversePrint(arr, index - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Reversed list: ";
    reversePrint(nums, nums.size() - 1);

    return 0;
}


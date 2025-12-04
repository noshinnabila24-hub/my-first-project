#include <iostream>
#include <vector>
using namespace std;


int firstOccurrence(const vector<int>& arr, int key) {
    int left = 0;
    int right = (int)arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}


int lastOccurrence(const vector<int>& arr, int key) {
    int left = 0;
    int right = (int)arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {

    vector<int> ids = {100, 100, 102, 105, 105, 105, 110};

    int key;
    cout << "Enter employee ID to search: ";
    cin >> key;

    int first = firstOccurrence(ids, key);
    int last = lastOccurrence(ids, key);

    if (first == -1) {
        cout << "ID " << key << " not found in the list." << endl;
    } else {
        cout << "First occurrence index : " << first << endl;
        cout << "Last occurrence index  : " << last << endl;
    }

    return 0;
}

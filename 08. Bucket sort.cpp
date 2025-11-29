#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void insertionSort(vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(vector<int>& arr, int numBuckets) {
    int n = arr.size();
    if (n <= 0) return;


    int lowest = arr[0], highest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < lowest) lowest = arr[i];
        if (arr[i] > highest) highest = arr[i];
    }


    vector<vector<int>> buckets(numBuckets);


    for (int i = 0; i < n; i++) {
        int index = (int)floor(((double)(arr[i] - lowest) / (highest - lowest)) * (numBuckets ));
        if (index >= numBuckets) index = numBuckets - 1;
        buckets[index].push_back(arr[i]);
    }


    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i]);
    }


    int idx = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    vector<int> arr = {42, 30, 33, 50, 37, 45, 60};
    int numBuckets = 5;

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, numBuckets);

    cout << "Sorted array:   ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


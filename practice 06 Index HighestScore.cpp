#include <iostream>
using namespace std;

int main() {
    int scores[5] = {45, 67, 89, 72, 90};
    int n = 5;

    int maxScore = scores[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            maxIndex = i;
        }
    }

    cout << "Highest Score = " << maxScore << endl;
    cout << "Index (0-based) = " << maxIndex << endl;
    cout << "Position (1-based) = " << maxIndex + 1 << endl;

    return 0;
}


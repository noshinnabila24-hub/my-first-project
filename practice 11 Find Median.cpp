#include <iostream>
using namespace std;
int main() {
    int class1[] = {50, 60, 70, 80};
    int class2[] = {55, 65, 75, 85, 95};

    int n1 = 4, n2 = 5;
    int total = n1 + n2;

    int i = 0, j = 0;
    int count = 0;
    int m1 = -1, m2 = -1;

    int medianPos1 = (total - 1) / 2;
    int medianPos2 = total / 2;

    while (count <= medianPos2) {
        int val;
        if (i < n1 && (j >= n2 || class1[i] <= class2[j])) {
            val = class1[i];
            i++;
        } else {
            val = class2[j];
            j++;
        }

        if (count == medianPos1) m1 = val;
        if (count == medianPos2) m2 = val;

        count++;
    }


    if (total % 2 == 0) {
        float median = (m1 + m2) / 2.0;
        cout << "Median = " << median << "\n";
    } else {
        cout << "Median = " << m2 << "\n";
    }

    return 0;
}


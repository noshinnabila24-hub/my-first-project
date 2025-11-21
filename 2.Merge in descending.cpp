#include <iostream>
using namespace std;

int main()
{
    int ara[1000];

    for (int i = 0; i < 1000; i++) {
        ara[i] = 999 - i;
    }

    int item_to_search = 5500;
    int flag = 0, step_linear = 0;

    for (int i = 0; i < 1000; i++) {
        if (ara[i] == item_to_search) {
            flag = 1;
            cout << "Found!";
        }
    }
    step_linear++;

    if (flag == 0) {
        cout << " not found";
    }

    int low = 0, high = 999;
    flag = 0;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (ara[mid] == item_to_search) {
            cout << "found";
            flag = 1;
            break;
        }
        else if (ara[mid] < item_to_search) {

            high = mid - 1;
        }
        else {

            low = mid + 1;
        }
    }

    return 0;
}


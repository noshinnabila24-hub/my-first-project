#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int weight[4] = {5, 4, 3, 2};
    int profit[4] = {60, 90, 70, 50};
    int capacity = 9;

    int bestProfit = 0;
    int chosen[4];
    int chosenCount = 0;


    for (int mask = 0; mask < (1 << n); mask++) {
        int totalWeight = 0, totalProfit = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                totalWeight += weight[i];
                totalProfit += profit[i];
            }
        }

        if (totalWeight > capacity) continue;

        if (totalProfit > bestProfit) {
            bestProfit = totalProfit;


            chosenCount = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    chosen[chosenCount] = i + 1;
                    chosenCount++;
                }
            }
        }
    }

    cout << "Best Profit = " << bestProfit << endl;
    cout << "Items chosen: ";

    for (int i = 0; i < chosenCount; i++) {
        cout << "Item-" << chosen[i] << " ";
    }

    cout << endl;
    return 0;
}

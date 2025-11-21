#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int weight[4] = {5, 4, 3, 2};
    int profit[4] = {60, 90, 70, 50};
    int capacity = 9;

    int dp[5][10];   // dp[n+1][capacity+1]

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){

            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(j >= weight[i-1]){
                dp[i][j] = max(dp[i-1][j],
                               profit[i-1] + dp[i-1][j - weight[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][capacity] << endl;

    return 0;
}


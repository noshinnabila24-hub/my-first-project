#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l;
    cin >> l;

    int profit[l+1];
    for(int i = 0; i <= l; i++){
        cin >> profit[i];
    }

    int dp[l+1][l+1];

    for(int i = 0; i <= l; i++){
        for(int j = 0; j <= l; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(j < i){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], profit[i] + dp[i][j - i]);
            }
        }
    }

    cout << "Maximum Profit is: " << dp[l][l];
    return 0;
}


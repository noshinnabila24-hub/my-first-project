#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)   // your own min function
{
    if(a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    int s;
    cin>>s;
    int n; //number of coin
    cin>>n;
    int coins[n];
    for(int i=0;i<n; i++)
    {
        cin>>coins[i];
    }

    //step1: Take dp table of size row=n+1, column=s+1
    int dp[n+1][s+1];

    //step 2: if i=0, then dp[i][j]=Infinity
    //if j=0, then dp[i][j]=0
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s;j++)
        {
            if(i==0)
            {
                dp[i][j]=INT_MAX;
            }
            if(j==0)
            {
                dp[i][j]=0;
                continue;
            }
            //check if the point can be taken
            //if not then leave it(copy previous value)
            else if(j<coins[i-1]|| dp[i][j-coins[i-1]]==INT_MAX)
            {
                dp[i][j]=dp[i-1][j];
            }
            //if include is possible, then take the minimum one
            else
            {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }

    if(dp[n][s]!=INT_MAX){
        cout<<"Min Number of coin: "<<dp[n][s];
    }

    return 0;
}

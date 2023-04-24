#include<bits/stdc++.h>
using namespace std;

int coin(vector<int> coins,int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                dp[i][j]=0;
            else if(j==0)
                dp[i][j]=1;
            else if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    int sum;
    cin>>sum;
    cout<<coin(coins,sum,n);
}
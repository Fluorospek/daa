#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> profit,vector<int> weight,int W,int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(weight[i-1]<=j)
            dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> profit;
    vector<int> weight;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        profit.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        weight.push_back(x);
    }
    int W;
    cin>>W;
    cout<<knapsack(profit,weight,W,n);
}
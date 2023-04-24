#include<bits/stdc++.h>
using namespace std;

int matrixChainOrder(vector<int> arr,int n)
{
    int dp[n][n];
    for(int i=0;i<n;i++)
    dp[i][i]=0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(q<dp[i][j])
                dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}

int main()
{
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Minimum number of multiplications is "<<matrixChainOrder(arr,n);
    return 0;
}
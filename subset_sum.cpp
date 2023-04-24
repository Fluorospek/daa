#include<bits/stdc++.h>
using namespace std;

void subset_sum(vector<int>& arr,int i,int sum,int curr_sum,int n,bool& flag,bool x[])
{
    if(i==n)
    {
        if(curr_sum==sum)
        flag=true;
        return;
    }
    x[i]=1;
    subset_sum(arr,i+1,sum,curr_sum+arr[i],n,flag,x);
    x[i]=0;
    subset_sum(arr,i+1,sum,curr_sum,n,flag,x);
}

void print_subset(vector<int>& arr,bool x[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(x[i])
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, sum;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>sum;
    bool flag=false;
    bool x[n];
    for(int i=0;i<n;i++)
    x[i]=0;
    subset_sum(arr,0,sum,0,n,flag,x);
    if(flag){
        cout<<"subset found"<<endl;
        print_subset(arr,x,n);
    }
    else
    cout<<"subset not found"<<endl;
}
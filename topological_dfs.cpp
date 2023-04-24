#include<bits/stdc++.h>
using namespace std;

class graph
{
    int n;
    vector<vector<int>> adj;

    void topological_sort_rec(int n,vector<int>& visited,stack<int>& stackk)
    {
        visited[n]=1;
        vector<int>::iterator it;
        for(it=adj[n].begin();it!=adj[n].end();it++)
        {
            if(!visited[*it])
            topological_sort_rec(*it,visited,stackk);
        }
        stackk.push(n);
    }

    public:

    graph(int n){
        this->n=n;
        adj.resize(n);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
    }

    void topological_sort()
    {
        stack<int> stackk;

        vector<int> visited(n,0);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            topological_sort_rec(i,visited,stackk);
        }

        while(!stackk.empty())
        {
            cout<<stackk.top()<<" ";
            stackk.pop();
        }
    }
};

int main()
{
    int n;
    cin>>n;
    graph g(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g.add_edge(x,y);
    }
    g.topological_sort();
}
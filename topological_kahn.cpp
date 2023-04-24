#include<bits/stdc++.h>
using namespace std;

class graph
{
    int n;
    vector<vector<int>> adj;

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
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int>::iterator it;
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                indegree[*it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        int count_visited=0;

        vector<int> topological_order;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            topological_order.push_back(curr);

            vector<int>::iterator it;
            for(it=adj[curr].begin();it!=adj[curr].end();it++)
            {
                if(--indegree[*it]==0)
                q.push(*it);
            }
            count_visited++;
        }
        if(count_visited!=n){
        cout<<"There exists a cycle in the graph";
        return;
        }

        for(int i=0;i<topological_order.size();i++)
        cout<<topological_order[i]<<" ";
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
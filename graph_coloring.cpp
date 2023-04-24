#include <bits/stdc++.h>
using namespace std;

#define V 4

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[],int v)
{
	if (v == V)
		return true;

	for (int c = 1; c <= m; c++) {
		if (isSafe(v, graph, color, c)) {
			color[v] = c;
			if (graphColoringUtil(graph, m, color, v + 1)
				== true)
				return true;
			color[v] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[V][V], int m)
{
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (graphColoringUtil(graph, m, color, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(color);
	return true;
}

void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i] << " ";

	cout << "\n";
}

int main()
{
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};

	int m = 3;

	graphColoring(graph, m);
	return 0;
}




// #include<bits/stdc++.h>
// using namespace std;

// bool isSafe(int v,vector<vector<int>>& adj,vector<int>& color,int c,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(adj[v][i] && c==color[i])
//         return false;
//     }
//     return true;
// }

// void print_solution(vector<int>& color,int n)
// {
//     for(int i=0;i<n;i++)
//     cout<<color[i]<<" ";
//     cout<<endl;
// }

// bool graph_coloring_rec(vector<vector<int>>& adj,int m,vector<int>& color,int n,int i)
// {
//     if(i==n)
//     return true;

//     for(int c=1;c<=m;c++)
//     {
//         if(isSafe(i,adj,color,c,n))
//         {
//             color[i]=c;

//             if(graph_coloring_rec(adj,m,color,n,i+1)==true)
//             return true;

//             color[i]=0;
//         }
//     }
// }

// bool graph_coloring(vector<vector<int>>& adj,int n,int m)
// {
//     vector<int> color(n,0);
//     if(graph_coloring_rec(adj,m,color,n,0)==false)
//     {
//         cout<<"Solution does not exist"<<endl;
//         return false;
//     }
//     print_solution(color,n);
//     return true;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++)
//     {
//         vector<int> temp;
//         for(int j=0;j<n;j++)
//         {
//             int x;
//             cin>>x;
//             temp.push_back(x);
//         }
//         adj.push_back(temp);
//     }

//     graph_coloring(adj,n,m);
// }
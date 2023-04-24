#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>& board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>>& board,int col,int row,int n)
{
    //checking if any queen is present in the same row to the left of the current queen
    for(int i=0;i<col;i++)
    if(board[row][i])
    return false;

    //checking if any queen is present in the lower diagonal to the left of the current queen
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    if(board[i][j])
    return false;

    //checking if any queen is present in the upper diagonal to the left of the current queen
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    if(board[i][j])
    return false;

    return true;
}

bool solveRec(vector<vector<int>>& board,int col,int n)
{
    if(col>=n)
    return true;

    //checking all the rows
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,col,i,n))
        {
            board[i][col]=1;
            if(solveRec(board,col+1,n))
            return true;

            //backtracking
            board[i][col]=0;
        }
    }

    return false;
}

bool solve_n_queen(int n)
{
    vector<vector<int>> board(n,vector<int> (n,0));
    if(solveRec(board,0,n)==false)
    {
        cout<<"No solution exists";
        return false;
    }
    printBoard(board,n);
    return true;
}

int main()
{
    int n;
    cin>>n;
    solve_n_queen(n);
}
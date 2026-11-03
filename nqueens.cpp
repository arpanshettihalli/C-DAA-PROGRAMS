#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>&board,int row,int col,int n)
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}
void solve(vector<vector<char>>&board,int row,int n)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]='Q';
            solve(board,row+1,n);
            board[row][col]='.';
        }

    }
}
int main()
{
    int n;
    cout<<"enter the number of queens"<<endl;
    cin>>n;
    vector<vector<char>>board(n,vector<char>(n,'.'));
    solve(board,0,n);
    return 0;
    
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}
vector<vector<int>> sub(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    vector<vector<int>> C(n, vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int n)
{
    if(n == 1)
        return {{A[0][0] * B[0][0]}};

    int k = n/2;

    vector<vector<int>> A11(k,vector<int>(k)), A12(k,vector<int>(k));
    vector<vector<int>> A21(k,vector<int>(k)), A22(k,vector<int>(k));

    vector<vector<int>> B11(k,vector<int>(k)), B12(k,vector<int>(k));
    vector<vector<int>> B21(k,vector<int>(k)), B22(k,vector<int>(k));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }

    vector<vector<int>> M1 = strassen(add(A11,A22,k),add(B11,B22,k),k);
    vector<vector<int>> M2 = strassen(add(A21,A22,k),B11,k);
    vector<vector<int>> M3 = strassen(A11,sub(B12,B22,k),k);
    vector<vector<int>> M4 = strassen(A22,sub(B21,B11,k),k);
    vector<vector<int>> M5 = strassen(add(A11,A12,k),B22,k);
    vector<vector<int>> M6 = strassen(sub(A21,A11,k),add(B11,B12,k),k);
    vector<vector<int>> M7 = strassen(sub(A12,A22,k),add(B21,B22,k),k);

    vector<vector<int>> C11 = add(sub(add(M1,M4,k),M5,k),M7,k);
    vector<vector<int>> C12 = add(M3,M5,k);
    vector<vector<int>> C21 = add(M2,M4,k);
    vector<vector<int>> C22 = add(sub(add(M1,M3,k),M2,k),M6,k);
        vector<vector<int>> C(n,vector<int>(n));

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+k]=C12[i][j];
            C[i+k][j]=C21[i][j];
            C[i+k][j+k]=C22[i][j];
        }
    }

    return C;
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>> A(n,vector<int>(n));
    vector<vector<int>> B(n,vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>B[i][j];

    vector<vector<int>> C = strassen(A,B,n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";

        cout<<endl;
    }
}
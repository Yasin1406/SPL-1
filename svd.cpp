#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;

int main(){
    int m,n,i,j;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<double>> matA,transA,symA;
    matA.resize(m,vector<double>(n));
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>matA[i][j];
        }
    }
    transpose(matA,transA);
    cout<<"Transpose:"<<endl;
    for(i=0;i<transA.size();i++){
        for(j=0;j<transA[i].size();j++){
            cout<<transA[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"A*At:"<<endl;
    multiplication(matA,transA,symA);
    for(i=0;i<symA.size();i++){
        for(j=0;j<symA[i].size();j++){
            cout<<symA[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

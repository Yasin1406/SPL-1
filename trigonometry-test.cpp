#include<bits/stdc++.h>
using namespace std;
#define upper 10
#define lower 0
//#define EPS 1e-3
#include "matrix_operations.cpp"

int main(){
    int m,n,i,j;
    vector<vector<double>> mat;
    mat.resize(5,vector<double>(3));
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            mat[i][j]=rand()%20;
        }
    }
    cout<<"Matrix:"<<endl;
    print_matrix(mat);
    cout<<"After swapping:"<<endl;
    swap_rows(mat,1,3);
    print_matrix(mat);
    return 0;
}

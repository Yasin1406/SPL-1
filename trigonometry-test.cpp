#include<bits/stdc++.h>
using namespace std;
#define upper 20
#define lower 0
//#define EPS 1e-3
#include "matrix_operations.cpp"
double Determinant(vector<vector<double>> &mat){
    int i,j,k,n=mat.size();
    if(!n){
        return 0;
    }
    if(n==1){
        return mat[0][0];
    }
    if(n==2){
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    double det=0;
    for(i=0;i<n;i++){
        vector<vector<double>> sub_mat;
        sub_mat.resize(n-1,vector<double>(n-1));
        sub_matrix(mat,0,i,sub_mat);
        det+=mat[0][i]*pow(-1,i)*Determinant(sub_mat);
    }
    return det;
}
int main(){
    int n,i,j;
    cout<<"Enter size of the matrix: ";
    cin>>n;
    vector<vector<double>> mat,in_mat;
    mat.resize(n,vector<double>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j]=(rand() %(upper - lower + 1)) + lower;
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    // vector<vector<double>> sub_mat;
    // sub_matrix(mat,1,2,sub_mat);
    // for(i=0;i<sub_mat.size();i++){
    //     for(j=0;j<sub_mat[i].size();j++){
    //         cout<<sub_mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
   // cout<<"Determinent: "<<determinant(mat)<<endl;
    inverse_matrix(mat,in_mat);
    cout<<"Inverse matrix:"<<endl;
    // print_matrix(in_mat);
    for(i=0;i<in_mat.size();i++){
        for(j=0;j<in_mat[i].size();j++){
            printf("%.3lf\t",in_mat[i][j]);
        }
        cout<<endl;
    }
    return 0;
}

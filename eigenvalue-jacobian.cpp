#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;

void get_eigen_values(vector<vector<double>> &mat1,vector<double> &eigen_values);

int main(){
    int n,i,j;
    cout<<"Enter number of rows: ";
    cin>>n;
    vector<vector<double>> mat1;
    mat1.resize(n,vector<double>(n));
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }
}

void get_eigen_values(vector<vector<double>> &mat1,vector<double> &eigen_values){
    int i,j;
    vector<int> index;
    double max=max_value(mat1,index),theta,tan_theta;
    vector<vector<double>> matP;
    matP.resize(mat1.size(),vector<double>(mat1.size()));
    for(i=0;i<matP.size();i++){
        if(i!=index[0]&&i!=index[1]){
            matP[i][i]=1;
        }   
    }
    tan_theta=(2*mat1[index[0]][index[1]])/(mat1[index[0]][index[0]]-mat1[index[1]][index[1]]);
    theta=0.5*atan(tan_theta);
    matP[index[0]][index[1]]=sin(theta);
    matP[index[1]][index[0]]=-sin(theta);
    matP[index[0]][index[0]]=cos(theta);
    matP[index[1]][index[1]]=cos(theta);
    
}
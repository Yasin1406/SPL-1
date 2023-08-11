#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;
#define EPS 1e-4
void get_eigen_values(vector<vector<double>> &mat1,vector<double> &eigen_values);

int main(){
    int n,i,j;
    cout<<"Enter number of rows: ";
    cin>>n;
    vector<vector<double>> mat1,mat2,mat3;
    vector<double> val;
    mat1.resize(n,vector<double>(n));
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }
  //  cout<<"1\n";
//     transpose(mat1,mat2);
//    // cout<<"1\n";
//     multiplication(mat1,mat2,mat3);
   // cout<<"1\n";
    get_eigen_values(mat1,val);
    // for(i=0;i<mat3.size();i++){
    //     for(j=0;j<mat3[i].size();j++){
    //         cout<<mat3[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"Eigenvalues: ";
    for(i=0;i<val.size();i++){
        cout<<val[i]<<" ";
    }
    cout<<endl;
}

void get_eigen_values(vector<vector<double>> &mat1,vector<double> &eigen_values){
    int i,j;
    eigen_values.resize(mat1.size());
    vector<int> index;
    double max=max_value(mat1,index),theta,tan_theta;
    vector<vector<double>> matP;
    matP.resize(mat1.size(),vector<double>(mat1.size()));
    
    for(i=0;i<matP.size();i++){
        matP[i][i]=1;
    }
    
    if(mat1[index[0]][index[0]]-mat1[index[1]][index[1]]==0){
        theta=0.5*asin(1);
    }
    else{
        tan_theta=(2*mat1[index[0]][index[1]])/(mat1[index[0]][index[0]]-mat1[index[1]][index[1]]);
        theta=0.5*atan(tan_theta);
    }
    cout<<"Theta: "<<theta<<endl;
    
    matP[index[0]][index[1]]=sin(theta);
    if(matP[index[0]][index[1]]<EPS){
        matP[index[0]][index[1]]=0;
    }

    matP[index[1]][index[0]]=-sin(theta);
    if(fabs(matP[index[1]][index[0]])<EPS){
        matP[index[1]][index[0]]=0;
    }

    matP[index[0]][index[0]]=cos(theta);
    if(matP[index[0]][index[0]]<EPS){
        matP[index[0]][index[0]]=0;
    }

    matP[index[1]][index[1]]=cos(theta);
    if(matP[index[1]][index[1]]<EPS){
        matP[index[1]][index[1]]=0;
    }

    cout<<endl;
    

    vector<vector<double>> new_mat1,transP,new_mat2;
    transpose(matP,transP);
    multiplication(transP,mat1,new_mat1);
    multiplication(new_mat1,matP,new_mat2);

    if(is_diagonal(new_mat2)){
        for(i=0;i<new_mat2.size();i++){
            eigen_values[i]=new_mat2[i][i];
        }
    }
    else{
        get_eigen_values(new_mat2,eigen_values);
    }
}
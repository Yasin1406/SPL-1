#include<bits/stdc++.h>
using namespace std;
#include "matrix_operations.cpp"
#define upper 10
#define lower 0
void inverse(vector<vector<double>> mat,vector<vector<double>> &in_mat){
    int i,j,k,n=mat.size(),cur,pre,p;
    double m;
    make_identical(in_mat,n);
    for(i=0;i<n-1;i++){
        for(p=i;p<n;p++){
            if(!(fabs(mat[p][i])<EPS)){
                break;
            }
        }
        if(p==n){
            cout<<"Solution doessn't exist!"<<endl;
            return;
        }
        if(fabs(mat[i][i])<EPS){
            vector<double> temp,in_temp;
            temp.resize(n);
            in_temp.resize(n);
            for(j=0;j<n;j++){
                temp[j]=mat[i][j];
                in_temp[j]=in_mat[i][j];
            }
            for(j=0;j<n;j++){
                in_mat[i][j]=in_mat[p][j];
            }
            for(j=0;j<n;j++){
                in_mat[p][j]=in_temp[j];
            }
        }
        for(j=i+1;j<n;j++){
            m=mat[j][i]/mat[i][i];
            for(k=0;k<n;k++){
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS){
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS){
                    in_mat[j][k]=0;
                }
            }
        }
    }
    if(fabs(mat[n-1][n-1])<EPS){
        cout<<"Solution doesn't exist"<<endl;
        return;
    }
    for(i=n-1;i>0;i--){
        for(j=i-1;j>=0;j--){
            m=mat[j][i]/mat[i][i];
            for(k=0;k<n;k++){
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS){
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS){
                    in_mat[j][k]=0;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        m=mat[i][i];
        for(j=0;j<n;j++){
            mat[j][i]/=m;
            in_mat[i][j]/=m;
        }
    }
    cout<<"\nIdentity:"<<endl;
    for(i=0;i<mat.size();i++){
        for(j=0;j<mat[i].size();j++){
            printf("%.3lf\t",mat[i][j]);
        }
        cout<<endl;
    }
  //  print_matrix(in_mat);
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
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    inverse(mat,in_mat);
    cout<<"Inverse matrix:"<<endl;
   // print_matrix(in_mat);
    for(i=0;i<in_mat.size();i++){
        for(j=0;j<in_mat[i].size();j++){
            printf("%.3lf\t",in_mat[i][j]);
        }
        cout<<endl;
    }
}
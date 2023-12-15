#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;
int iter;
void eigenvalue(vector<vector<double>> A,vector<double> &values);
int main(){
    int m,n,i,j;
    vector<vector<double>> mat;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    mat.resize(m,vector<double>(n));
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<double>> A,t_mat;
    vector<double> values;
    values.resize(n);
    transpose(mat,t_mat);
    cout<<"\nTranspose of the matrix:"<<endl;
    for(i=0;i<t_mat.size();i++){
        for(j=0;j<t_mat[i].size();j++){
            printf("%.3f\t",t_mat[i][j]);
        }
        cout<<endl;
    }
    multiplication(t_mat,mat,A);
    cout<<"\nThe symmetric matrix:"<<endl;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[i].size();j++){
            printf("%.3f\t",A[i][j]);
        }
        cout<<endl;
    }
    eigenvalue(A,values);
    // eigenvalue(mat,values);
    cout<<"\nEigenvalues: ";
    for(i=0;i<values.size();i++){
        printf("%.3f\t",values[i]);
    }
    cout<<endl;
    return 0;
}
void eigenvalue(vector<vector<double>> A,vector<double> &values){
    // cout<<"--------------------------------------------------"<<endl;
    // cout<<"Iteration "<<++iter<<endl;
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    // printf("Maximum off diagonal value: %.3f\n",max);
    // cout<<"Indices: "<<inI<<","<<inJ<<endl;
    vector<vector<double>> S,t_S,A_new,temp;
    make_identity(S,A.size());
    if(A[inI][inI]==A[inJ][inJ]){
        theta=0.5*asin(1);
        if(A[inI][inI]<0){
            theta=-theta;
        }
    }
    else{
        theta=0.5*atan((2*A[inI][inJ])/fabs(A[inI][inI]-A[inJ][inJ]));
    }
    // printf("Theta: %.3f\n",theta);
    S[inI][inJ]=-sin(theta);
    S[inJ][inI]=sin(theta);
    S[inI][inI]=cos(theta);
    S[inJ][inJ]=cos(theta);
    transpose(S,t_S);
    multiplication(t_S,A,temp);
    multiplication(temp,S,A_new);
    // cout<<"\nS'AS matrix:"<<endl;
    // for(i=0;i<A_new.size();i++){
    //     for(j=0;j<A_new[i].size();j++){
    //         printf("%.3f\t",A_new[i][j]);
    //     }
    //     cout<<endl;
    // }
    // cout<<"--------------------------------------------------"<<endl;
    if(!is_diagonal(A_new)){
        eigenvalue(A_new,values);
    }
    else{
        cout<<"\nS'AS matrix:"<<endl;
        for(i=0;i<A_new.size();i++){
            for(j=0;j<A_new[i].size();j++){
                printf("%.3f\t",A_new[i][j]);
            }
            cout<<endl;
        }
        for(i=0;i<A_new.size();i++){
            values[i]=A_new[i][i];
        }
    }
}
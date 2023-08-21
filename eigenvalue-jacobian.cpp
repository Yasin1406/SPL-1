#include<bits/stdc++.h>
#include "matrix_operations.cpp"
#define upper 0
#define lower 20
using namespace std;
int iter;
void eigenvalue(vector<vector<double>> A,vector<double> &values);
vector<vector<double>> eigen_vector;
int main(){
    int m,n,i,j;
    vector<vector<double>> mat;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    mat.resize(m,vector<double>(n));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mat[i][j]=(rand() %(upper - lower + 1)) + lower;
        }
    }
    vector<vector<double>> A,t_mat;
    vector<double> values;
    values.resize(n);
    transpose(mat,t_mat);
    multiplication(t_mat,mat,A);
    cout<<"\nThe symmetric matrix:"<<endl;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    make_identical(eigen_vector,n);
    eigenvalue(A,values);
    cout<<"\n"<<endl;
    for(i=0;i<values.size();i++){
        printf("Eigenvectors for eigenvalue %.3lf:\n",values[i]);
        for(j=0;j<eigen_vector.size();j++){
            printf("%.3lf ",eigen_vector[j][i]);
        }
        cout<<"\n"<<endl;
    }
    cout<<endl;
    return 0;
}
void eigenvalue(vector<vector<double>> A,vector<double> &values){
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    vector<vector<double>> S,t_S,A_new,temp,temp_S;
    make_identical(S,A.size());
    if(A[inI][inI]==A[inJ][inJ]){
        theta=0.5*asin(1);
        if(A[inI][inI]<0){
            theta=-theta;
        }
    }
    else{
        theta=0.5*atan((2*A[inI][inJ])/fabs(A[inI][inI]-A[inJ][inJ]));
    }
    S[inI][inJ]=-sin(theta);
    S[inJ][inI]=sin(theta);
    S[inI][inI]=cos(theta);
    S[inJ][inJ]=cos(theta);
    transpose(S,t_S);
    multiplication(t_S,A,temp);
    multiplication(temp,S,A_new);
    multiplication(eigen_vector,S,temp_S);
    matrix_copy(temp_S,eigen_vector);
    if(!is_diagonal(A_new)){
        eigenvalue(A_new,values);
    }
    else{
        for(i=0;i<A_new.size();i++){
            if(fabs(A_new[i][i])<10e-3){
                A_new[i][i]=0;
            }
            values[i]=A_new[i][i];
        }
        for(j=0;j<eigen_vector.size();j++){
            for(i=0;i<eigen_vector.size();i++){
                eigen_vector[i][j]/=eigen_vector[eigen_vector.size()-1][j];
            }
        }
    }
}
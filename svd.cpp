#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;
#define upper 20
#define lower -20
void calculate_eigenvalues(vector<vector<double>> A,vector<vector<double>> &eigen_values,vector<vector<double>> &eigen_vectors);
void normalized_eigen_vector(vector<vector<double>> &eigen_vectors);
void inverse_sigma(vector<vector<double>> sigma,vector<vector<double>> &t_sigma);
int main(){
    srand(time(0));
    int i,j,m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<double>> mat;
    mat.resize(m,vector<double>(n));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mat[i][j]=(rand()%(upper-lower+1))+lower;
        }
    }
    cout<<"Randomly generated matrix:"<<endl;
    print_matrix(mat);
    vector<vector<double>> t_mat,A,eigen_vectors;
    vector<double> eigen_values;
    transpose(mat,t_mat);
    if(m>=n){
        multiplication(t_mat,mat,A);
        make_identity(eigen_vectors,n);

    }
    
    return 0;
}
void calculate_eigenvalues(vector<vector<double>> A,vector<vector<double>> &eigen_values,vector<vector<double>> &eigen_vectors){
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    vector<vector<double>> rotation,t_rotation;
    make_identity(rotation,A.size());
    if(A[inI][inI]==A[inJ][inJ]){
        if(A[inI][inJ]>0){
            theta=0.5*asin(1);
        }
        else{
            theta=-0.5*asin(1);
        }
    }
    else{
        theta=0.5*atan((2*A[inI][inJ])/(A[inI][inI]-A[inJ][inJ]));
    }
    rotation[inI][inI]=cos(theta);
    rotation[inJ][inJ]=cos(theta);
    rotation[inI][inJ]=-sin(theta);
    rotation[inJ][inI]=sin(theta);
    transpose(rotation,t_rotation);
    vector<vector<double>> temp;
    multiplication(t_rotation,A,temp);
    multiplication(temp,rotation,A);
    temp.clear();
    multiplication(eigen_vectors,rotation,temp);
    matrix_copy(temp,eigen_vectors);
    if(!is_diagonal(A)){
        calculate_eigenvalues(A,eigen_values,eigen_vectors);
    }
    else{
        for(i=0;i<A.size();i++){
            if(fabs(A[i][i])<EPS){
                A[i][i]=0;
            }
        }
        for(j=0;i<eigen_vectors.size();j++){
            for(i=0;i<eigen_vectors.size();i++){
                eigen_vectors[i][j]/=eigen_vectors[eigen_vectors.size()-1][j];
            }
        }
    }
}
void normalized_eigen_vector(vector<vector<double>> &eigen_vectors){
    int i,j,k;
    double norm;
    for(i=0;i<eigen_vectors.size();i++){
        norm=euclidean_norm_col(eigen_vectors,i);
        for(j=0;j<eigen_vectors.size();j++){
            eigen_vectors[j][i]/=norm;
        }
    }
}
void inverse_sigma(vector<vector<double>> sigma,vector<vector<double>> &t_sigma){
    
}
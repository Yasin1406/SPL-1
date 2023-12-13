#include<bits/stdc++.h>
#include "matrix.cpp"
using namespace std;

void calculate_pseudo_inverse(vector<vector<double>> mat,vector<vector<double>> &inverse_mat);
void svd(vector<vector<double>> mat,vector<vector<double>> &U_mat,vector<vector<double>> &sigma_mat,vector<vector<double>> &V_mat);
void eigen_values_and_eigen_vectors(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vectors);
void normalized_eigen_vector(vector<vector<double>> &eigen_vectors);
void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat);

// int main(){
//     int n;
//     cin>>n;
//     vector<vector<double>> mat,in_mat;
//     mat.resize(n,vector<double>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>mat[i][j];
//         }
//     }
//     calculate_pseudo_inverse(mat,in_mat);
//     cout<<"Pseudo inverse:"<<endl;
//     print_matrix(in_mat);
//     return 0;
// }

void calculate_pseudo_inverse(vector<vector<double>> mat,vector<vector<double>> &inverse_mat){
    
    vector<vector<double>> U_mat,sigma_mat,V_mat;
    svd(mat,U_mat,sigma_mat,V_mat);
    
    vector<vector<double>> temp;
    transpose(V_mat,temp);
    matrix_copy(temp,V_mat);
    vector<vector<double>> t_U_mat;
    transpose(U_mat,t_U_mat);
    
    vector<vector<double>> i_sigma_mat;
    inverse_sigma(sigma_mat,i_sigma_mat);
    temp.clear();
    transpose(i_sigma_mat,temp);
    matrix_copy(temp,i_sigma_mat);
    temp.clear();
    multiplication(V_mat,i_sigma_mat,temp);
    multiplication(temp,t_U_mat,inverse_mat);
}

void svd(vector<vector<double>> mat,vector<vector<double>> &U_mat,vector<vector<double>> &sigma_mat,vector<vector<double>> &V_mat){
    int n=mat.size();
    int i,j;

    vector<double> eigen_values;
    vector<vector<double>> eigen_vectors;
    eigen_values.resize(n);
    vector<vector<double>> t_mat,A;

    transpose(mat,t_mat);
    multiplication(t_mat,mat,A);
    make_identity(eigen_vectors,n);

    eigen_values_and_eigen_vectors(A,eigen_values,eigen_vectors);

    vector<vector<double>> t_eigen_vectors;
    transpose(eigen_vectors,t_eigen_vectors);

    vector<double> sorted_eigen_values;
    sorted_eigen_values.resize(eigen_values.size());
    for(i=eigen_values.size()-1;i>=0;i--){
        for(j=i-1;j>=0;j--){
            if(eigen_values[i]>eigen_values[j]){
                double temp;
                temp=eigen_values[i];
                eigen_values[i]=eigen_values[j];
                eigen_values[j]=temp;
                swap_rows(t_eigen_vectors,i,j);
            }
        }
    }

    transpose(t_eigen_vectors,eigen_vectors);
    normalized_eigen_vector(eigen_vectors);

    sigma_mat.resize(n,vector<double>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                sigma_mat[i][j]=sqrt(eigen_values[i]);
            }
            else{
                sigma_mat[i][j]=0;
            }
        }
    }

    vector<vector<double>> i_sigma_mat,temp,temp1;
    inverse_sigma(sigma_mat,i_sigma_mat);
    multiplication(mat,eigen_vectors,temp);
    multiplication(temp,i_sigma_mat,U_mat);
    transpose(eigen_vectors,V_mat);
    // cout<<"Left singular matrix:"<<endl;
    // print_matrix(U_mat);
    // cout<<endl;
    // cout<<"Singular matrix:"<<endl;
    // print_matrix(sigma_mat);
    // cout<<endl;
    // cout<<"Right singular matrix:"<<endl;
    // print_matrix(V_mat);
    // cout<<endl;
    // multiplication(U_mat,sigma_mat,temp1);
    // multiplication(temp1,right_sing,ans);
}

void eigen_values_and_eigen_vectors(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vectors){
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    vector<vector<double>> S,t_S,A_new,temp,temp_S;
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
    S[inI][inJ]=-sin(theta);
    S[inJ][inI]=sin(theta);
    S[inI][inI]=cos(theta);
    S[inJ][inJ]=cos(theta);
    transpose(S,t_S);
    multiplication(t_S,A,temp);
    multiplication(temp,S,A_new);
    multiplication(eigen_vectors,S,temp_S); 
    matrix_copy(temp_S,eigen_vectors);
    if(!is_diagonal(A_new)){
        eigen_values_and_eigen_vectors(A_new,eigen_values,eigen_vectors);
    }
    else{
        for(i=0;i<A_new.size();i++){
            if(fabs(A_new[i][i])<10e-3){
                A_new[i][i]=0;
            }
            eigen_values[i]=A_new[i][i];
        }
        for(j=0;j<eigen_vectors.size();j++){
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

void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat){
    int i;
    int n=sigma_mat.size();
    make_identity(i_sigma_mat,n);
    // i_sigma_mat.resize(n,vector<double>(n));
    for(i=0;i<n;i++){
        if(sigma_mat[i][i]!=0){
            i_sigma_mat[i][i]=1/sigma_mat[i][i];
        }
        else{
            i_sigma_mat[i][i]=0;
        }
    }
}

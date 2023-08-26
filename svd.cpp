#include<bits/stdc++.h>
// #include "matrix_operations.cpp"
#include "eigenvalue-jacobian.cpp"
using namespace std;
#define upper 20
#define lower -20
vector<vector<double>> eigen_vector;
vector<double> eigen_value;
int main(){
    int m,n,i,j;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<double>> matA,t_matA,mat;
    matA.resize(m,vector<double>(n));
    // cout<<"Enter the matrix:"<<endl;
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         cin>>matA[i][j];
    //     }
    // }
    cout<<"The matrix:"<<endl;
    for(i=0;i<matA.size();i++){
        for(j=0;j<matA[i].size();j++){
            matA[i][j]=(rand()%(upper-lower+1))+lower;
            cout<<matA[i][j]<<" ";
        }
        cout<<endl;
    }
    transpose(matA,t_matA);
  //  cout<<"Transposed successfully"<<endl;
    multiplication(t_matA,matA,mat);
   // cout<<"Multiplied successfully"<<endl;
    eigen_value.resize(mat.size());
    eigen_vector.resize(mat.size(),vector<double>(mat.size()));
    eigenvalue(mat,eigen_value,eigen_vector);

    vector<vector<double>> sigma;
    make_identity(sigma,eigen_vector.size());
    for(i=0;i<sigma.size();i++){
        sigma[i][i]=sqrt(eigen_value[i]);
    }
    cout<<endl;
    cout<<"Eigenvalues:"<<endl;
    for(i=0;i<eigen_value.size();i++){
        printf("%.3lf\t",eigen_value[i]);
    }
    cout<<endl;
    for(i=0;i<eigen_vector.size();i++){
        for(j=0;j<eigen_vector[i].size();j++){
            printf("%.3lf\t",eigen_vector[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The Sigma matrix:"<<endl;
    for(i=0;i<sigma.size();i++){
        for(j=0;j<sigma[i].size();j++){
            printf("%.3lf\t",sigma[i][j]);
        }
        cout<<endl;
    }
    return 0;
}

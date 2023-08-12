#include<bits/stdc++.h>
#include "matrix_operations.cpp"
using namespace std;
#define EPS 10e-4
void get_eigen_values(vector<vector<double>> &mat1,vector<double> &eigen_values);
int iter;
int main(){
    int m,n,i,j;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<double>> mat1,mat2,mat3;
    vector<double> val;
    val.resize(n);
    mat1.resize(m,vector<double>(n));
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }
    // transpose(mat1,mat2);
    // multiplication(mat1,mat2,mat3);
    // get_eigen_values(mat3,val);
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
    if(iter==8){
        return;
    }
    int i,j;
    int inI,inJ;
    vector<vector<double>> matD,matS,matS1,matS1t,tempD,matD_new,matS_new;
    matrix_copy(mat1,matD);
    make_identical(matS,mat1.size());
    matrix_copy(matS,matS1);
    double max=max_off_diagonal_value(matD,inI,inJ),theta,tan_theta;
    cout<<"Max off diagonal value: "<<max<<" Index: "<<inI<<" "<<inJ<<endl;
    if(matD[inI][inI]==matD[inJ][inJ]){
        theta=0.5*asin(1);
        if(matD[inI][inJ]<=0){
            theta=-theta;
        }
    }
    else{
        theta=0.5*atan((2*matD[inI][inJ])/(matD[inI][inJ]-matD[inJ][inI]));
    }
    cout<<"Theta: "<<theta<<endl;
    matS1[inI][inI]=cos(theta);
    if(fabs(matS1[inI][inI])<EPS){
        matS1[inI][inI]=0;
    }
    matS1[inJ][inJ]=cos(theta);
    if(fabs(matS1[inJ][inJ])<EPS){
        matS1[inJ][inJ]=0;
    }
    matS1[inI][inJ]=sin(theta);
    if(fabs(matS1[inI][inJ])<EPS){
        matS1[inI][inJ]=0;
    }
    matS1[inJ][inI]=-sin(theta);
    if(fabs(matS1[inJ][inI])<EPS){
        matS1[inJ][inI]=0;
    }
    transpose(matS1,matS1t);
    multiplication(matS1t,matD,tempD);
    multiplication(tempD,matS1,matD_new);
    for(i=0;i<matD_new.size();i++){
        for(j=0;j<matD_new[i].size();j++){
            printf("%.3lf\t",matD_new[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
    if(sqrt(off_diagonal_sq_sum(matD_new))<EPS){
        cout<<"Got eigenvalues!"<<endl;
        for(i=0;i<matD_new.size();i++){
            eigen_values[i]=matD_new[i][i];
        }
    }
    else{
        iter++;
        get_eigen_values(matD_new,eigen_values);
    }



   // vector<vector<double>> matP;
    // matP.resize(mat1.size(),vector<double>(mat1.size()));
    
    // for(i=0;i<matP.size();i++){
    //     matP[i][i]=1;
    // }
    
    // if(mat1[index[0]][index[0]]-mat1[index[1]][index[1]]==0){
    //     theta=0.5*asin(1);
    //     if(mat1[index[0]][index[1]]<0){
    //         theta=-theta;
    //     }
    // }
    // else{
    //     tan_theta=(2*mat1[index[0]][index[1]])/(mat1[index[1]][index[1]]-mat1[index[0]][index[0]]);
    //     theta=0.5*atan(tan_theta);
    // }
    // if(fabs(theta)<EPS){
    //     theta=0;
    // }
    // cout<<"Theta: "<<theta<<endl;
    
    // matP[index[0]][index[1]]=sin(theta);
    // if(matP[index[0]][index[1]]<EPS){
    //     matP[index[0]][index[1]]=0;
    // }

    // matP[index[1]][index[0]]=-sin(theta);
    // if(fabs(matP[index[1]][index[0]])<EPS){
    //     matP[index[1]][index[0]]=0;
    // }

    // matP[index[0]][index[0]]=cos(theta);
    // if(matP[index[0]][index[0]]<EPS){
    //     matP[index[0]][index[0]]=0;
    // }

    // matP[index[1]][index[1]]=cos(theta);
    // if(matP[index[1]][index[1]]<EPS){
    //     matP[index[1]][index[1]]=0;
    // }

//     cout<<endl;
    

//     vector<vector<double>> new_mat1,transP,new_mat2;
//    // transpose(matP,transP);
//     multiplication(transP,mat1,new_mat1);
//  //   multiplication(new_mat1,matP,new_mat2);

//     if(is_diagonal(new_mat2)){
//         for(i=0;i<new_mat2.size();i++){
//             eigen_values[i]=new_mat2[i][i];
//         }
//     }
//     else{
//         get_eigen_values(new_mat2,eigen_values);
//     }
}
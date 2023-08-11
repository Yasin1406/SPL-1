#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-4
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2);
void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
double determinant(vector<vector<double>> &mat);
double max_value(vector<vector<double>> &mat1,vector<int> &index);
bool is_diagonal(vector<vector<double>> &mat1);
// int main(){
//     int m1,m2,n1,n2;
//     vector<vector<double>> mat1,mat2,mat3;
//     cout<<"Enter the dimension of the 1st matrix: ";
//     cin>>m1>>n1;
//     // cout<<"Enter the dimension of the 2nd matrix: ";
//     // cin>>m2>>n2;
//     int i,j;
//     mat1.resize(m1,vector<double>(n1));

//     //mat2.resize(m2,vector<double>(n2));
    
    
//     printf("Enter matrix-1:\n");
//     for(i=0;i<m1;i++){
//         for(j=0;j<n1;j++){
//             cin>>mat1[i][j];
//         }
//     }

//     vector<int> maxIn;
// //     transpose(mat1,mat2);
// //     multiplication(mat1,mat2,mat3);
// //     printf("Enter matrix-2:\n");
// //     for(i=0;i<m2;i++){
// //         for(j=0;j<n2;j++){
// //             cin>>mat2[i][j];
// //         }
// //     }

// //     addition(mat1,mat2,mat3);
// //     subtraction(mat1,mat2,mat3);
// //     transpose(mat1,mat2);
// //     cout<<"After subtracition:\n";
// //     for(i=0;i<m1;i++){
// //         for(j=0;j<n1;j++){
// //             cout<<mat3[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //     multiplication(mat1,mat2,mat3);
// //     cout<<"After multiplication:"<<endl;
// //     for(i=0;i<mat3.size();i++){
// //         for(j=0;j<mat3[i].size();j++){
// //             cout<<mat3[i][j]<<" ";
// //         }
// //         cout<<endl;
// //     }
// //    cout<<determinant(mat1)<<endl;
//     if(is_diagonal(mat1)){
//         cout<<"Yes"<<endl;
//     }
//     else{
//         cout<<"No"<<endl;
//    }
//    //cout<<max_value(mat1,maxIn)<<endl;
//    return 0;

// }
void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    mat3.resize(mat1.size(),vector<double>(mat1[0].size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat3[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2){
    mat2.resize(mat1[0].size(),vector<double>(mat1.size()));
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++){
            mat2[j][i]=mat1[i][j];
        }
    }
}

void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3){
    int i,j,k;
    if(mat1[0].size()!=mat2.size()){
        cout<<"Dimension doesn't match for multiplication!"<<endl;
        return;
    }
    mat3.resize(mat1.size(),vector<double> (mat2[0].size()));
    for(i=0;i<mat1.size();i++){
        for(j=0;j<mat2[0].size();j++){
            for(k=0;k<mat2.size();k++){
                mat3[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    for(i=0;i<mat3.size();i++){
        for(j=0;j<mat3.size();j++){
            if(fabs(mat3[i][j])<EPS){
                mat3[i][j]=0;
            }
            if(fabs(floor(mat3[i][j])-mat3[i][j])<EPS){
                mat3[i][j]=floor(mat3[i][j]);
            }
            if(fabs(ceil(mat3[i][j])-mat3[i][j])<EPS){
                mat3[i][j]=ceil(mat3[i][j]);
            }
        }
    }
}

double determinant(vector<vector<double>> &mat){
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
        int sub_row=0,sub_col;
        for(j=1;j<n;j++){
            sub_col=0;
            for(k=0;k<n;k++){
                if(k!=i){
                    sub_mat[sub_row][sub_col]=mat[j][k];
                    sub_col++;
                }
            }
            sub_row++;
        }
        det+=mat[0][i]*pow(-1,i)*determinant(sub_mat);
    }
    return det;
}

double max_value(vector<vector<double>> &mat1,vector<int> &index){
    int i,j;
    index.resize(2);
    double max=mat1[0][1];
        for(i=0;i<mat1.size();i++){
            for(j=0;j<mat1[i].size();j++){ 
                if(i!=j&&mat1[i][j]>max){
                    max=mat1[i][j];
                //    cout<<i<<j<<endl;
                    index[0]=i;
                    index[1]=j;
                }
            }
    }
    return max;
}

bool is_diagonal(vector<vector<double>> &mat1){
    int i,j;
    for(i=0;i<mat1.size();i++){
        for(j=0;j<mat1.size();j++){
            if(i!=j){
                if(mat1[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}
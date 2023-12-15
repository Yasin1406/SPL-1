#include<bits/stdc++.h>
using namespace std;
#define EPS 10e-6

void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2);
void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3);
double determinant(vector<vector<double>> &mat);
double max_off_diagonal_value(vector<vector<double>> mat1,int &inI,int &inJ);
bool is_diagonal(vector<vector<double>> &mat1);
double off_diagonal_sq_sum(vector<vector<double>> mat);
void make_identity(vector<vector<double>> &mat,int size);
void matrix_copy(vector<vector<double>> mat1,vector<vector<double>> &mat2);
void sub_matrix(vector<vector<double>> mat,int I,int J,vector<vector<double>> &sub_mat);
void inverse_matrix(vector<vector<double>> mat,vector<vector<double>> &in_mat);
void print_matrix(vector<vector<double>> mat);
void print_aug_matrix(vector<vector<double>> mat,vector<vector<double>> aug_mat);
double euclidean_norm_col(vector<vector<double>> mat,int col);
void sigma_matrix(vector<double> eigen_value,vector<vector<double>> &mat,int row,int col);
void swap_rows(vector<vector<double>> &mat,int I,int J);
void calculate_pseudo_inverse(vector<vector<double>> mat,vector<vector<double>> &inverse_mat);
void svd(vector<vector<double>> mat,vector<vector<double>> &U_mat,vector<vector<double>> &sigma_mat,vector<vector<double>> &V_mat);
void eigen_values_and_eigen_vectors(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vectors);
void normalized_eigen_vector(vector<vector<double>> &eigen_vectors);
void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat);

void addition(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    mat3.clear();
    vector<double> temp;
    double value;
    for(int i=0;i<mat1.size();i++)
    {
        for(int j=0;j<mat1[i].size();j++)
        {
            value=mat1[i][j]+mat2[i][j];
            temp.push_back(value);
        }
        mat3.push_back(temp);
        temp.clear();
    }
}

void subtraction(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    mat3.clear();
    vector<double> temp;
    double value;
    for(int i=0;i<mat1.size();i++)
    {
        for(int j=0;j<mat1[i].size();j++)
        {
            value=mat1[i][j]-mat2[i][j];
            temp.push_back(value);
        }
        mat3.push_back(temp);
        temp.clear();
    }
}

void transpose(vector<vector<double>> &mat1,vector<vector<double>> &mat2)
{
    mat2.clear();
    int row=mat1.size();
    int col=mat1[0].size();
    int i,j;
    vector<double> temp;
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            temp.push_back(mat1[j][i]);
        }
        mat2.push_back(temp);
        temp.clear();
    }
}

void multiplication(vector<vector<double>> &mat1,vector<vector<double>> &mat2,vector<vector<double>> &mat3)
{
    int i,j,k;
    if(mat1[0].size()!=mat2.size())
    {
        cout<<"Dimension doesn't match for multiplication!"<<endl;
        return;
    }
    double value;
    vector<double> temp;
    for(i=0;i<mat1.size();i++)
    {
        for(j=0;j<mat2[0].size();j++)
        {
            value=0;
            for(k=0;k<mat2.size();k++)
            {
                value+=mat1[i][k]*mat2[k][j];
            }
            temp.push_back(value);
        }
        mat3.push_back(temp);
        temp.clear();
    }
    for(i=0;i<mat3.size();i++)
    {
        for(j=0;j<mat3[i].size();j++)
        {
            if(fabs(mat3[i][j])<EPS)
            {
                mat3[i][j]=0;
            }
        }
    }
}

double determinant(vector<vector<double>> &mat)
{
    int i,j,k,n=mat.size();
    if(!n)
    {
        return 0;
    }
    if(n==1)
    {
        return mat[0][0];
    }
    if(n==2)
    {
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    double det=0;
    for(i=0;i<n;i++)
    {
        vector<vector<double>> sub_mat;
        sub_matrix(mat,0,i,sub_mat);
        det+=mat[0][i]*pow(-1,i)*determinant(sub_mat);
    }
    return det;
}

double max_off_diagonal_value(vector<vector<double>> mat1,int &inI,int &inJ)
{
    int i,j;
    double max=0;
    inI=0;
    inJ=1;
    for(i=0;i<mat1.size();i++)
    {
        for(j=0;j<mat1[i].size();j++)
        { 
            if(i!=j&&fabs(mat1[i][j])>fabs(max))
            {
                max=mat1[i][j];
                inI=i;
                inJ=j;
            }
        }
    }
    return max;
}

bool is_diagonal(vector<vector<double>> &mat1)
{
    int i,j;
    for(i=0;i<mat1.size();i++)
    {
        for(j=0;j<mat1.size();j++)
        {
            if(i!=j)
            {
                if(mat1[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

double off_diagonal_sq_sum(vector<vector<double>> mat)
{
    double sq;
    int i,j;
    for(i=0;i<mat.size();i++)
    {
        for(j=0;j<mat[i].size();j++)
        {
            if(i!=j)
            {
                sq+=pow(mat[i][j],2);
            }
        }
    }
    return sq;
}

void make_identity(vector<vector<double>> &mat,int size)
{
    mat.clear();
    vector<double> temp;
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(i!=j)
            {
                temp.push_back(0);
            }
            else
            {
                temp.push_back(1);
            }
        }
        mat.push_back(temp);
        temp.clear();
    }
}

void matrix_copy(vector<vector<double>> mat1,vector<vector<double>> &mat2)
{
    mat2.clear();
    vector<double> temp;
    int i,j;
    for(i=0;i<mat1.size();i++)
    {
        for(j=0;j<mat1[i].size();j++)
        {
            temp.push_back(mat1[i][j]);
        }
        mat2.push_back(temp);
        temp.clear();
    }
}

void sub_matrix(vector<vector<double>> mat,int I,int J,vector<vector<double>> &sub_mat)
{
    sub_mat.resize(mat.size()-1,vector<double>(mat.size()-1));
    int i,j,k,sub_row=0,sub_col;
    for(i=0;i<mat.size();i++)
    {
        if(i!=I)
        {
            sub_col=0;
            for(j=0;j<mat[i].size();j++)
            {
                if(j!=J)
                {
                    sub_mat[sub_row][sub_col++]=mat[i][j];
                }
            }
            sub_row++;
        }  
    }
}

void inverse_matrix(vector<vector<double>> mat,vector<vector<double>> &in_mat)
{
    int i,j,k,n=mat.size(),cur,pre,p;
    double m;
    make_identity(in_mat,n);
    for(i=0;i<n-1;i++)
    {
        for(p=i;p<n;p++)
        {
            if(!(fabs(mat[p][i])<EPS))
            {
                break;
            }
        }
        if(p==n)
        {
            return;
        }
        if(fabs(mat[i][i])<EPS)
        {
            swap_rows(mat,i,p);
            swap_rows(in_mat,i,p);
        }
        for(j=i+1;j<n;j++)
        {
            m=mat[j][i]/mat[i][i];
            for(k=0;k<n;k++)
            {
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS)
                {
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS)
                {
                    in_mat[j][k]=0;
                }
            }
        }
    }
    if(fabs(mat[n-1][n-1])<EPS)
    {
        cout<<"Inverse doesn't exist!"<<endl;
        return;
    }
    for(i=n-1;i>0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            m=mat[j][i]/mat[i][i];
            for(k=0;k<n;k++)
            {
                mat[j][k]-=m*mat[i][k];
                if(fabs(mat[j][k])<EPS)
                {
                    mat[j][k]=0;
                }
                in_mat[j][k]-=m*in_mat[i][k];
                if(fabs(in_mat[j][k])<EPS)
                {
                    in_mat[j][k]=0;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        m=mat[i][i];
        for(j=0;j<n;j++)
        {
            mat[j][i]/=m;
            in_mat[i][j]/=m;
        }
    }
}

void print_matrix(vector<vector<double>> mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
        {
            printf("%10.3lf",mat[i][j]);
        }
        cout<<endl;
    }
}

void print_aug_matrix(vector<vector<double>> mat,vector<vector<double>> aug_mat)
{
    int i,j;
    for(i=0;i<mat.size();i++)
    {
        for(j=0;j<mat[i].size();j++)
        {
            printf("%10.3lf\t",mat[i][j]);
        }
        cout<<"| ";
        for(j=0;j<aug_mat[i].size();j++)
        {
            printf("%10.3lf\t",aug_mat[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}

double euclidean_norm_col(vector<vector<double>> mat,int col)
{
    double norm=0;
    int i,j;
    for(i=0;i<mat.size();i++)
    {
        norm+=mat[i][col]*mat[i][col];
    }
    return sqrt(norm);
}
void sigma_matrix(vector<double> eigen_value,vector<vector<double>> &mat,int row,int col)
{
    int i,j;
    vector<double> temp;
    mat.clear();
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            temp.push_back(0.0);
        }
        mat.push_back(temp);
        temp.clear();
    }
    for(i=0;i<mat.size();i++)
    {
        mat[i][i]=sqrt(eigen_value[i]);
    }
}

void swap_rows(vector<vector<double>> &mat,int I,int J)
{
    vector<double> temp;
    int i,j;
    for(i=0;i<mat[I].size();i++)
    {
        temp.push_back(mat[I][i]);
    }
    for(i=0;i<mat[I].size();i++)
    {
        mat[I][i]=mat[J][i];
    }
    for(i=0;i<mat[I].size();i++)
    {
        mat[J][i]=temp[i];
    }
}

void calculate_pseudo_inverse(vector<vector<double>> mat,vector<vector<double>> &inverse_mat)
{
    
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

void svd(vector<vector<double>> mat,vector<vector<double>> &U_mat,vector<vector<double>> &sigma_mat,vector<vector<double>> &V_mat)
{
    int n=mat.size();
    int i,j;

    vector<double> eigen_values;
    vector<vector<double>> eigen_vectors;
    vector<vector<double>> t_mat,A;

    transpose(mat,t_mat);
    multiplication(t_mat,mat,A);
    make_identity(eigen_vectors,n);

    eigen_values_and_eigen_vectors(A,eigen_values,eigen_vectors);

    vector<vector<double>> t_eigen_vectors;
    transpose(eigen_vectors,t_eigen_vectors);

    for(i=eigen_values.size()-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(eigen_values[i]>eigen_values[j])
            {
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
    sigma_matrix(eigen_values,sigma_mat,n,n);

    vector<vector<double>> i_sigma_mat,temp,temp1;
    inverse_sigma(sigma_mat,i_sigma_mat);
    multiplication(mat,eigen_vectors,temp);
    multiplication(temp,i_sigma_mat,U_mat);
    transpose(eigen_vectors,V_mat);
}

void eigen_values_and_eigen_vectors(vector<vector<double>> A,vector<double> &eigen_values,vector<vector<double>> &eigen_vectors)
{
    int inI,inJ,i,j;
    double theta;
    double max=max_off_diagonal_value(A,inI,inJ);
    vector<vector<double>> S,t_S,A_new,temp,temp_S;
    make_identity(S,A.size());
    if(A[inI][inI]==A[inJ][inJ])
    {
        theta=0.5*asin(1);
        if(A[inI][inI]<0)
        {
            theta=-theta;
        }
    }
    else
    {
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
    if(!is_diagonal(A_new))
    {
        eigen_values_and_eigen_vectors(A_new,eigen_values,eigen_vectors);
    }
    else
    {
        for(i=0;i<A_new.size();i++)
        {
            if(fabs(A_new[i][i])<10e-3)
            {
                A_new[i][i]=0;
            }
            eigen_values.push_back(A_new[i][i]);
        }
        for(j=0;j<eigen_vectors.size();j++)
        {
            for(i=0;i<eigen_vectors.size();i++)
            {
                eigen_vectors[i][j]/=eigen_vectors[eigen_vectors.size()-1][j];
            }
        }
    }
}

void normalized_eigen_vector(vector<vector<double>> &eigen_vectors)
{
    int i,j,k;
    double norm;
    for(i=0;i<eigen_vectors.size();i++)
    {
        norm=euclidean_norm_col(eigen_vectors,i);
        for(j=0;j<eigen_vectors.size();j++)
        {
            eigen_vectors[j][i]/=norm;
        }
    }
}

void inverse_sigma(vector<vector<double>> sigma_mat,vector<vector<double>> &i_sigma_mat)
{
    int i;
    int n=sigma_mat.size();
    make_identity(i_sigma_mat,n);
    for(i=0;i<n;i++)
    {
        if(sigma_mat[i][i]!=0)
        {
            i_sigma_mat[i][i]=1/sigma_mat[i][i];
        }
        else
        {
            i_sigma_mat[i][i]=0;
        }
    }
}

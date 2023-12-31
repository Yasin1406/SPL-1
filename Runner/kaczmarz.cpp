#include<bits/stdc++.h>
using namespace std;
#define eps 10e-5

vector<vector<double>> x;
int m,n;
void kaczmarz_operation(vector<vector<double>> A,vector<double> b,vector<double> &sol,int iter);
double inner_product(vector<vector<double>> A,int row,int k);
double norm_sq(vector<vector<double>> A,int row);
void kaczmarz(vector<vector<double>> A,vector<double> b,int k);

void kaczmarz_operation(vector<vector<double>> A,vector<double> b,vector<double> &sol,int iter){
    x.clear();
    sol.clear();
    n=A.size();
    m=A[0].size();
    int i,j;
    vector<double> temp;
    for(i=0;i<m;i++)
    {
        temp.push_back(0);
    }
    x.push_back(temp);
    for(i=1;i<=iter;i++)
    {
        kaczmarz(A,b,i);
    }
    cout<<endl;
    for(auto s:x[i-1])
    {
        sol.push_back(s);
    }
}

double inner_product(vector<vector<double>> A,int row,int k)
{
    double prod=0;
    for(int i=0;i<n;i++)
    {
        prod+=A[row][i]*x[k][i];
    }
    return prod;
}

double norm_sq(vector<vector<double>> A,int row)
{
    double sq_sum;
    for(int i=0;i<n;i++)
    {
        sq_sum+=pow(A[row][i],2);
    }
    return sq_sum;
}

void kaczmarz(vector<vector<double>> A,vector<double> b,int k)
{
    int index=(k-1)%m;
    double coefficient;
    double dot_prod=inner_product(A,index,k-1);
    double norm=norm_sq(A,index);
    double value;
    coefficient=(b[index]-dot_prod)/norm;
    vector<double> temp;
    int i;
    for(i=0;i<m;i++)
    {
        value=x[k-1][i]+coefficient*A[index][i];
        if(fabs(value)<eps)
        {
            value=0;
        }
        temp.push_back(value);
    }

    x.push_back(temp);
}
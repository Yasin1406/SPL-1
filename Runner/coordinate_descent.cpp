#include<bits/stdc++.h>
using namespace std;

void normalize_feature(vector<vector<double>> &X);
void initialize_w(vector<double> &w,int n);
void coordinate_descent_operation(vector<vector<double>> X,vector<double> y,vector<double> &w);
double calculate_residual(vector<vector<double>> X,vector<double> y,vector<double> w);
double calculate_dot_prod(vector<vector<double>> X,vector<double> w,int j);
double calculate_w_j(vector<vector<double>> X,double residual_without_j,int j);

int main()
{
    vector<vector<double>> X;
    vector<double> y,w;
    int n,i,j;
    cout<<"Enter size of the matrix: ";
    cin>>n;
    cout<<"Enter the augmented matrix:"<<endl;
    vector<double> row;
    double value;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>value;
            row.push_back(value);
        }
        X.push_back(row);
        row.clear();
        cin>>value;
        y.push_back(value);
    }
    coordinate_descent_operation(X,y,w);
    for(auto v:w)
    {
        cout<<v<<endl;
    }
    return 0;
}

void normalize_feature(vector<vector<double>> &X)
{
    int i,j;
    int n=X.size();
    double sq_sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sq_sum+=X[i][j]*X[i][j];
        }
    }
    sq_sum=sqrt(sq_sum);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            X[i][j]/=sq_sum;
        }
    }
}

void initialize_w(vector<double> &w,int n)
{
    int i=0;
    while(i<n)
    {
        w.push_back(0);
        i++;
    }
}

void coordinate_descent_operation(vector<vector<double>> X,vector<double> y,vector<double> &w)
{
    int n=X.size();
    normalize_feature(X);
    initialize_w(w,n);
    int iter=0;
    double residual;
    int i,j;
    double residual_without_j;
    double dot_prod;
    while(iter<100)
    {
        residual=calculate_residual(X,y,w);
        for(j=0;j<n;j++)
        {
            dot_prod=calculate_dot_prod(X,w,j);
            residual_without_j=residual+dot_prod;
            w[j]=calculate_w_j(X,residual_without_j,j);
            residual=residual-dot_prod;
        }
        iter++;
    }
}

double calculate_residual(vector<vector<double>> X,vector<double> y,vector<double> w)
{
    int n=X.size();
    int i,j;
    double sum=0;
    double temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            temp+=X[i][j]*w[j];
        }
        sum+=y[i]-temp;
    }
    return sum;
}

double calculate_dot_prod(vector<vector<double>> X,vector<double> w,int j)
{
    double sum=0;
    int n=X.size();
    int i=0;
    while(i<n)
    {
        sum+=X[i][j]*w[j];
        i++;
    }
    return sum;
}

double calculate_w_j(vector<vector<double>> X,double residual_without_j,int j)
{
    double sum=0;
    int i=0;
    int n=X.size();
    while(i<n)
    {
        sum+=X[i][j]*residual_without_j;
        i++;
    }
    return sum;
}
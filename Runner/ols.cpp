#include<bits/stdc++.h>
#include "matrix.cpp"
using namespace std;

vector<vector<double>> X,t_X,mul_X,inverse_mul_X,mul,ans;
vector<vector<double>> Y;
void ols_operation(vector<vector<double>> mat,vector<double> cons,vector<double> &sol)
{
    sol.clear();
    int i,j;
    X=mat;
    for(auto c:cons)
    {
        Y.push_back({c});
    }
    transpose(X,t_X);
    multiplication(t_X,X,mul_X);
    double det;
    det=determinant(mul_X);
    if(fabs(det)<EPS)
    {
        calculate_pseudo_inverse(mul_X,inverse_mul_X);
    }
    else{
        inverse_matrix(mul_X,inverse_mul_X);
    }
    multiplication(inverse_mul_X,t_X,mul);
    multiplication(mul,Y,ans);
    for(auto a:ans){
        for(auto v:a){
            sol.push_back(v);
        }
    }
    X.clear();
    t_X.clear();
    mul_X.clear();
    inverse_mul_X.clear();
    mul.clear();
    ans.clear();
    Y.clear();
}
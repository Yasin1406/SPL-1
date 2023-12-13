#include<bits/stdc++.h>
using namespace std;

#define eps 10e-5

vector<vector<double>> x;
// vector<vector<double>> A;
// vector<double> b;
int n;
double inner_product(vector<vector<double>> A,int row,int k);
double norm_sq(vector<vector<double>> A,int row);
void kaczmarz(vector<vector<double>> A,vector<double> b,int k);
void kaczmarz_operation(vector<vector<double>> A,vector<double> b,vector<double> &sol){
    n=A.size();
    // m=A.size();
    int i,j;
    vector<double> temp;
    for(i=0;i<n;i++){
        temp.push_back(0);
    }
    x.push_back(temp);
    for(i=1;i<=1000;i++){
        kaczmarz(A,b,i);
    }
    cout<<endl;
    for(auto s:x[i-1]){
        sol.push_back(s);
    }
}
// int main(){
//     cout<<"Enter number of rows and columns: ";
//     cin>>m>>n;
//     A.resize(m,vector<double>(n));
//     b.resize(n);
//     int i,j,k;
//     cout<<"Enter the augmented Arix:"<<endl;
//     for(i=0;i<m;i++){
//         for(j=0;j<n;j++){
//             cin>>A[i][j];
//         }
//         cin>>b[i];
//     }
//     vector<double> temp;
//     for(i=0;i<n;i++){
//         temp.push_back(0);
//     }
//     x.push_back(temp);
//     for(i=1;i<=1000;i++){
//         kaczmarz(i);
//     }
//     cout<<endl;
//     for(j=0;j<n;j++){
//         printf("X[%d]: %.3lf\n",j,x[i-1][j]);
//     }
    
// }
double inner_product(vector<vector<double>> A,int row,int k){
    double prod=0;
    for(int i=0;i<n;i++){
        prod+=A[row][i]*x[k][i];
    }
    return prod;
}
double norm_sq(vector<vector<double>> A,int row){
    double sq_sum;
    for(int i=0;i<n;i++){
        sq_sum+=pow(A[row][i],2);
    }
    return sq_sum;
}
void kaczmarz(vector<vector<double>> A,vector<double> b,int k){
    int index=(k-1)%n;
    double coefficient=(b[index]-inner_product(A,index,k-1))/norm_sq(A,index),value;
    vector<double> temp;
    int i;
    for(i=0;i<n;i++){
        value=x[k-1][i]+coefficient*A[index][i];
        if(fabs(value)<eps){
            value=0;
        }
        temp.push_back(value);
    }

    x.push_back(temp);
}
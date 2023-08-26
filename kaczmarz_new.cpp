#include<bits/stdc++.h>
using namespace std;

#define EPS 10e-5

vector<vector<double>> x;
vector<vector<double>> A;
vector<double> b;
int m,n;
double inner_product(int row,int k);
double norm_sq(int row);
void kaczmarz(int k);
int main(){
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    A.resize(m,vector<double>(n));
    b.resize(n);
    int i,j,k;
    cout<<"Enter the augmented matrix:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>A[i][j];
        }
        cin>>b[i];
    }
    vector<double> temp;
    for(i=0;i<n;i++){
        temp.push_back(0);
    }
    x.push_back(temp);
    for(i=1;i<=2000;i++){
        kaczmarz(i);
        cout<<"Iter: "<<i<<endl;
        for(j=0;j<n;j++){
            cout<<"x["<<j<<"]="<<x[i][j]<<endl;
        }
        cout<<endl;
    }
    
}
double inner_product(int row,int k){
    double prod=0;
    for(int i=0;i<n;i++){
        prod+=A[row][i]*x[k][i];
    }
    return prod;
}
double norm_sq(int row){
    double sq_sum;
    for(int i=0;i<n;i++){
        sq_sum+=pow(A[row][i],2);
    }
    return sq_sum;
}
void kaczmarz(int k){
    int index=(k-1)%m;
    double coefficient=(b[index]-inner_product(index,k-1))/norm_sq(index),value;
    vector<double> temp;
    int i;
    for(i=0;i<n;i++){
        value=x[k-1][i]+coefficient*A[index][i];
        if(fabs(value)<EPS){
            value=0;
        }
        temp.push_back(value);
    }
    x.push_back(temp);
}
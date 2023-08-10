#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> A,vec;
vector<double> X;
int n;

double in_prod(int i,int k){
    int j;
    double sum;
    for(j=0;j<n;j++){
        sum+=A[i][j]*vec[k][j];
    }
    return sum;
}

int main(){
    vector<double> temp;
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(4);
    A.push_back(temp);
    temp.clear();
    temp.push_back(5);
    temp.push_back(7);
    temp.push_back(1);
    vec.push_back(temp);
    
    n=3;
    cout<<in_prod(0,0)<<endl;
}
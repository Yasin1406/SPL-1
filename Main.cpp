#include<bits/stdc++.h>
#include "kaczmarz_new.cpp"
#include "ols.cpp"
using namespace std;
int main(){
    vector<vector<double>> mat;
    vector<double> cons;
    vector<double> solution;
    int n;
    cout<<"Enter size of the matrix: ";
    cin>>n;
    double value;
    vector<double> temp;
    int i,j;
    cout<<"Enter the augmented matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>value;
            temp.push_back(value);
        }
        mat.push_back(temp);
        temp.clear();
        cin>>value;
        cons.push_back(value);
    }
    kaczmarz_operation(mat,cons,solution);
    cout<<"Solution using kaczmarz:"<<endl;
    for(auto s:solution){
        printf("%.3lf\n",s);
    }
    cout<<endl<<endl;
    cout<<"Solution using ols:"<<endl;
    ols_operation(mat,cons);
    return 0;
}
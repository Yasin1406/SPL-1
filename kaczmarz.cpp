#include<bits/stdc++.h>
using namespace std;

#define EPS 10e-5
vector<vector<double>> vec;
vector<vector<double>> A;
vector<double> x,b;
int m,n,iter;

double row_sq_sum(int index);

bool kaczmarz(int k);

double dot_multiplication(int i,int k);

int main(){
    int i,j;
    cout<<"Enter number of equations and variables: ";
    cin>>m>>n;
    A.resize(m,vector<double>(n));
    //vec.resize(m,vector<double>(n));
    x.resize(n);
    b.resize(m);
    
    vec.push_back(x);

    cout<<"Enter the matrix:\n";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>A[i][j];
        }
        cin>>b[i];
    }
    
    for(i=0;i<n;i++){
        vec[0][i]=0.001;
    }
    
    // for(i=1;i<=20;i++){
    //     kaczmarz(i);
    // }
    i=1;
    while(kaczmarz(i++));
    return 0;
}

double row_sq_sum(int index){
    int i;
    double sum;
    for(i=0;i<n;i++){
        sum+=A[index][i]*A[index][i];
    }
    return sum;
}

bool kaczmarz(int k){
    int i,j;
    int index=k%m;
    double in_prod=dot_multiplication(index,k-1);
    double mul=(b[index]-in_prod)/row_sq_sum(index);
    double ess;
    cout<<"Iter: "<<++iter<<endl;
   // cout<<"In product: "<<in_prod<<endl;
   // cout<<"Row sum square: "<<row_sq_sum(index)<<endl;
    //cout<<"Mul: "<<mul<<endl;
    // for(i=0;i<n;i++){
    //     // vec[k][i]=(((vec[k-1][i])+(b[index]-dot_multiplication(index,k)))*A[index][i])/row_sq_sum(index);
    //     // cout<<"1\n";
        

    // }
    vector<double> temp;
    for(i=0;i<n;i++){
        temp.push_back(vec[k-1][i]+(mul*A[index][i]));
        ess=(vec[k-1][i]-temp[i])*(vec[k-1][i]-temp[i]);
    }
    vec.push_back(temp);
    for(i=0;i<n;i++){
        cout<<"x"<<i+1<<": "<<vec[iter][i]<<endl;
    }
    cout<<"\n\n";
    if(ess<=EPS){
        return false;
    }
    else{
        return true;
    }
}

double dot_multiplication(int i,int k){
    int j;
    double sum;
    for(j=0;j<n;j++){
        sum+=A[i][j]*vec[k][j];
    }
    return sum;
}
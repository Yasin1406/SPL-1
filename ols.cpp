#include<bits/stdc++.h>
// #include "matrix_operations.cpp"
#include "pseudo_inverse.cpp"
using namespace std;

vector<vector<double>> X,t_X,mul_X,inverse_mul_X,mul,ans;
vector<vector<double>> Y;
int m,n;

int main(){
    int i,j;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    X.resize(m,vector<double>(n));
    Y.resize(n,vector<double>(1));
    cout<<"Enter the augmented matrix:"<<endl;
    for(i=0;i<m;i++){
        // X[i][0]=1;
        for(j=0;j<n;j++){
            cin>>X[i][j];
        }
        cin>>Y[i][0];
    }

    cout<<"X:"<<endl;
    print_matrix(X);
    cout<<endl;

    transpose(X,t_X);
    cout<<"t_X:"<<endl;
    print_matrix(t_X);
    cout<<endl;

    multiplication(t_X,X,mul_X);
    // multiplication(X,t_X,mul_X);

    cout<<"(X^t*X):"<<endl;
    print_matrix(mul_X);
    cout<<endl;
    
    // inverse_matrix(mul_X,inverse_mul_X);
    calculate_pseudo_inverse(mul_X,inverse_mul_X);
    cout<<"(X^t*X)^-1:"<<endl;
    print_matrix(inverse_mul_X);
    cout<<endl;

    multiplication(inverse_mul_X,t_X,mul);
    // multiplication(inverse_mul_X,X,mul);

    cout<<"((X^t*X)^-1)*X^t:"<<endl;
    print_matrix(mul);
    cout<<endl;

    multiplication(mul,Y,ans);
    cout<<"Solution:"<<endl;
    print_matrix(ans);
    return 0;
}
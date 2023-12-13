#include<bits/stdc++.h>
// #include "matrix_operations.cpp"
#include "matrix.cpp"
using namespace std;
 
int main(){
    vector<vector<double>> m={{1,2,3},{4,0,6},{7,8,9}},in_mat;
    cout<<determinant(m)<<endl;
    inverse_matrix(m,in_mat);
    // calculate_pseudo_inverse(m,in_mat);
    // print_matrix(in_mat);
    // transpose(m,in_mat);
    print_matrix(in_mat);
    return 0;
}
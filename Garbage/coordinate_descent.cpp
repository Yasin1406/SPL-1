#include<bits/stdc++.h>
using namespace std;


void normalize_feature(vector<vector<double>> &X);
double calculate_residual(vector<vector<double>> X,vector<double> y,vector<double> w);
void coordinate_descent_operation(vector<vector<double>> X,vector<double> y,vector<double> &w);
double dot_product(vector<vector<double>> X,vector<double> w,int J);
double calculate_residual_without_j(vector<vector<double>> X,vector<double> y,vector<double> w,int I,int J);
int main(){
    vector<vector<double>> X;
    vector<double> y,w;
    int n;
    cout<<"Enter size of the matrix: ";
    cin>>n;
    vector<double> temp;
    double value;
    int i,j;
    cout<<"Enter the augmented matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>value;
            temp.push_back(value);
        }
        X.push_back(temp);
        temp.clear();
        cin>>value;
        y.push_back(value);
    }
    coordinate_descent_operation(X,y,w);
    cout<<"Solution:"<<endl;
    for(auto v:w){
        cout<<v<<endl;
    }
    // normalize_feature(X);
    // double sq_sum=0;
    // for(auto a:X){
    //     for(auto v:a){
    //         sq_sum+=v*v;
    //     }
    // }
    // cout<<sq_sum<<endl;
    return 0;
}

void coordinate_descent_operation(vector<vector<double>> X,vector<double> y,vector<double> &w){
    int iter=0;
    int n=X.size();
    int i,j;
    double residual;
    double residual_without_j;
    double temp,sum;
    normalize_feature(X);
    for(i=0;i<n;i++){
        w.push_back(0);
    }
    while(iter<1000){
        // residual=calculate_residual(X,y,w);
        // for(j=0;j<n;j++){
        //     sum=0;
        //     residual_without_j=residual+dot_product(X,w,j);
        //     for(i=0;i<n;i++){
        //         sum+=X[i][j]*residual_without_j;
        //     }
        //     w[j]=sum;
        //     residual=residual-dot_product(X,w,j);
        // }
        for(j=0;j<n;j++){
            sum=0;
            for(i=0;i<n;i++){
                residual_without_j=calculate_residual_without_j(X,y,w,i,j);
                sum+=X[i][j]*residual_without_j;
            }
            w[j]=sum;
        }
        iter++;
    }
}

// void normalize_feature(vector<vector<double>> &A,vector<double> &y){
//     int n=A.size();
//     double sq_sum=0;
//     for(auto a:A){
//         for(auto v:a){
//             sq_sum+=v*v;
//         }
//     }
//     sq_sum=sqrt(sq_sum);
//     for(int i=0;i<A.size();i++){
//         for(int j=0;j<A[i].size();j++){
//             A[i][j]/=sq_sum;
//         }
//     }
//     sq_sum=0;
//     for(int i=0;i<n;i++){
//         sq_sum+=y[i]*y[i];
//     }
//     sq_sum=sqrt(sq_sum);
//     for(int i=0;i<n;i++){
//         y[i]/=sq_sum;
//     }
// }
void normalize_feature(vector<vector<double>> &X) {
    int n=X.size();
    double mean;
    double std_dev;
    double sum=0;
    int i,j;
    // for(j=0;j<n;j++){
    //     sum=0;
    //     for(i=0;i<n;i++){
    //         sum+=X[i][j];
    //     }
    //     mean=sum/n;
    //     sum=0;
    //     for(i=0;i<n;i++){
    //         sum+=pow((X[i][j]-mean),2);
    //     }
    //     std_dev=sqrt(sum/n);
    //     for(i=0;i<n;i++){
    //         X[i][j]=(X[i][j]-mean)/std_dev;
    //     }
    // }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum+=X[i][j];
        }
    }
    mean=sum/(n*n);
    sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum+=(X[i][j]-mean)*(X[i][j]-mean);
        }
    }
    std_dev=sqrt(sum/n*n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            X[i][j]=(X[i][j]-mean)/std_dev;
        }
    }
    cout<<"After normalizing feature:"<<endl;
    for(auto x:X){
        for(auto v:x){
            printf("%10.3lf",v);
        }
        cout<<endl;
    }
}

// void normalize_feature(vector<vector<double>> &X){
//     int n=X.size();
//     double sq_sum;
//     int i,j;
//     for(j=0;j<n;j++){
//         sq_sum=0;
//         for(i=0;i<n;i++){
//             sq_sum+=X[i][j]*X[i][j];
//         }
//         sq_sum=sqrt(sq_sum);
//         for(i=0;i<n;i++){
//             X[i][j]/=sq_sum;
//         }
//     }
//     cout<<"After normalizing feature:"<<endl;
//     for(auto x:X){
//         for(auto v:x){
//             printf("%10.3lf",v);
//         }
//         cout<<endl;
//     }
// }


double calculate_residual(vector<vector<double>> X,vector<double> y,vector<double> w){
    int i,j;
    int n=X.size();
    double sum=0;
    double temp;
    for(i=0;i<n;i++){
        temp=0;
        for(j=0;j<n;j++){
            temp+=X[i][j]*w[j];
        }
        sum+=y[i]-temp;
    }
    return sum;
}

double dot_product(vector<vector<double>> X,vector<double> w,int J){
    int j;
    int n=X.size();
    double prod;
    double sum=0;
    for(int i=0;i<n;i++){
        prod=X[i][J]*w[J];
        sum+=prod;
    }
    return sum;
}


double calculate_residual_without_j(vector<vector<double>> X,vector<double> y,vector<double> w,int I,int J){
    int n=X.size();
    int i,j;
    double sum=0;
    for(j=0;j<n;j++){
        if(j==J){
            continue;
        }
        sum+=X[I][j]*w[J];
    }
    // cout<<"Y"<<endl;
    return y[I]-sum;
}
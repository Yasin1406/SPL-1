#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-3
int main(){
    double x;
    cin>>x;
    if(fabs(floor(x)-x)<EPS){
        x=floor(x);
    }
    if(fabs(ceil(x)-x)<EPS){
        x=ceil(x);
    }
    cout<<x<<endl;
    return 0;
}
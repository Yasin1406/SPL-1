#include<bits/stdc++.h>
using namespace std;
void create_augmented_matrix(vector<vector<double>> &A,vector<double> &b,int m,int n)
{
    A.clear();
    b.clear();    
    srand(time(NULL));
    int lb=-9;
    int ub=9;
    int i,j;
    vector<double> temp;
    double value;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            value=(rand()%(ub-lb+1))+lb;
            temp.push_back(value);
        }
        A.push_back(temp);
        temp.clear();
        value=(rand()%(ub-lb+1))+lb;
        b.push_back(value);
    }
}
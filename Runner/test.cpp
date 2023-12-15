#include<bits/stdc++.h>
#define thresh 10e-4
#define Eps 10e-6
using namespace std;

bool difference_check(vector<double> X,vector<double> Y)
{
    int i=0;
    int m=X.size();
    int n=Y.size();
    double diff;
    double numerator;
    double denominator;
    if(m!=n)
    {
        return true;
    }
    while(i<m)
    {
        if(fabs(X[i])<Eps)
        {
            if(fabs(Y[i])>thresh)
            {
                return true;
            }
        }
        else if(fabs(Y[i])<Eps)
        {
            if(fabs(X[i])>thresh){
                return true;
            }
        }
        else
        {
            if(fabs(X[i])<fabs(Y[i]))
            {
                numerator=X[i];
                denominator=Y[i];
            }
            else
            {
                numerator=Y[i];
                denominator=X[i];
            }
            diff=1-fabs(numerator/denominator);
            if(diff>thresh)
            {
                return true;
            }
        }
        i++;
    }
    return false;
}

bool check_validity(vector<double> X)
{
    int n=X.size();
    int i=0;
    while(i<n)
    {
        if(isnan(X[i])==true)
        {
            return false;
        }
        i++;
    }
    return true;
}

// double calculate_z_score(double x_value,double y_value,double Sx,double Sy);
// double calculate_standard_deviation(vector<double> x);
// void detect_outlier(vector<double> x,vector<double> y,vector<double> &outliers);
// double calculate_variance(vector<double> x);
// double calculate_mean(vector<double> x);

// double calculate_z_score(double x_value,double y_value,double Sx,double Sy)
// {
//     double z_score=(x_value-y_value)/(Sx+Sy);   
//     return fabs(z_score);
// }

// void detect_outlier(vector<double> x,vector<double> y,vector<double> &outliers)
// {
//     outliers.clear();
//     double Sx=calculate_standard_deviation(x);
//     double Sy=calculate_standard_deviation(y);
//     double z_score;
//     double threshold=2;
//     int i;
//     for(i=0;i<x.size();i++)
//     {
//         z_score=calculate_z_score(x[i],y[i],Sx,Sy);
//         if(z_score>threshold)
//         {
//             outliers.push_back(i);
//         }
//     }
// }

// double calculate_variance(vector<double> x)
// {
//     int n=x.size();
//     double mean=calculate_mean(x);
//     double sq_sum=0.0; 
//     double variance;

//     for(double v:x)
//     {
//         sq_sum+=v*v;
//     }

//     variance=(sq_sum-(n*mean*mean))/(n-1);

//     return variance;
// }

// double calculate_standard_deviation(vector<double> x)
// {
//     double variance=calculate_variance(x);
//     double std_dev=sqrt(variance);
//     return std_dev;
// }

// double calculate_mean(vector<double> x){
//     double sum=0;
//     int n=x.size();
//     double mean;
    
//     for(double v:x){
//         sum+=v;
//     }

//     mean=sum/n;
    
//     return mean;
// }


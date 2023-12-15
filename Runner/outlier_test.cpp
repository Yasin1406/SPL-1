#include<bits/stdc++.h>
using namespace std;

double calculate_z_score(double x_value,double y_value,double Sx,double Sy);
double calculate_standard_deviation(vector<double> x);
void detect_outlier(vector<double> x,vector<double> y,vector<double> &outliers);
double calculate_variance(vector<double> x);
double calculate_mean(vector<double> x);

double calculate_z_score(double x_value,double y_value,double Sx,double Sy)
{
    double z_score=(x_value-y_value)/Sx+Sy;   
    return z_score;
}

void detect_outlier(vector<double> x,vector<double> y,vector<double> &outliers)
{
    outliers.clear();
    double Sx=calculate_standard_deviation(x);
    double Sy=calculate_standard_deviation(y);
    double z_score;
    double threshold=2.0;
    int i;
    for(i=0;i<x.size();++i)
    {
        z_score=calculate_z_score(x[i],y[i],Sx,Sy);
        if(z_score>threshold)
        {
            outliers.push_back(i);
        }
    }
}

double calculate_variance(vector<double> x)
{
    int n=x.size();
    double mean=calculate_mean(x);
    double sq_sum=0.0; 
    double variance;

    for(double v:x)
    {
        sq_sum+=v*v;
    }

    variance=(sq_sum-(n*mean*mean))/(n-1);

    return variance;
}

double calculate_standard_deviation(vector<double> x)
{
    double variance=calculate_variance(x);
    double std_dev=sqrt(variance);
    return std_dev;
}

double calculate_mean(vector<double> x){
    double sum=0;
    int n=x.size();
    double mean;
    
    for(double v:x){
        sum+=v;
    }

    mean=sum/n;
    
    return mean;
}
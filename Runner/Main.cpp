#include<bits/stdc++.h>
#include "kaczmarz.cpp"
#include "ols.cpp"
#include "outlier_test.cpp"
using namespace std;

int main()
{
    vector<vector<double>> mat;
    vector<double> cons;
    vector<double> kaczmarz_solution,ols_solution;
    vector<double> outliers;
    int n;
    int iter;
    double value;
    vector<double> temp;
    int i,j;
    int choice;
    cout<<endl;
    cout<<"Choices:"<<endl;
    cout<<"1. Enter solution process"<<endl;
    cout<<"2. Quit"<<endl<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice!=1&&choice!=2)
    {
        cout<<endl<<"Invalid choice!"<<endl<<endl;
        cout<<"Please enter your choice again: ";
        cin>>choice;
    }
    while(choice!=2)
    {
        mat.clear();
        cons.clear();
        temp.clear();
        kaczmarz_solution.clear();
        ols_solution.clear();
        cout<<"Enter size of the matrix: ";
        cin>>n;
    
        cout<<"Enter the augmented matrix:"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>value;
                temp.push_back(value);
            }
            mat.push_back(temp);
            temp.clear();
            cin>>value;
            cons.push_back(value);
        }
        cout<<"Enter number of iterations for kaczmarz operation: ";
        cin>>iter;
        kaczmarz_operation(mat,cons,kaczmarz_solution,iter);
        cout<<"Solution using Kaczmarz:"<<endl;
        for(auto s:kaczmarz_solution)
        {
            printf("%.3lf\n",s);
        }
        cout<<endl<<endl;
        ols_operation(mat,cons,ols_solution);
        cout<<"Solution using OLS:"<<endl;
        for(auto s:ols_solution)
        {
            printf("%.3lf\n",s);
        }
        cout<<endl<<endl;
        detect_outlier(kaczmarz_solution,ols_solution,outliers);
        if(outliers.size()>0)
        {
            cout<<"There is 'significant differences' between the solutions of Kaczmarz method and OLS method ";
            cout<<"when using "<<iter<<" iterations"<<endl;
        }
        else{
            cout<<"There is 'no significant difference' between the solutions of Kaczmarz method and OLS method ";
            cout<<"when using "<<iter<<" iterations"<<endl;
        }
        cout<<endl;
        cout<<"Choices:"<<endl;
        cout<<"1. Enter solution process"<<endl;
        cout<<"2. Quit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        while(choice!=1&&choice!=2)
        {
            cout<<"Invalid choice!"<<endl;
            cout<<"Please enter your choice again: ";
            cin>>choice;
        }
    }
    
    return 0;
}
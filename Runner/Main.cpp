#include<bits/stdc++.h>
#include "kaczmarz.cpp"
#include "ols.cpp"
#include "test.cpp"
#include "generate.cpp"
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
    string choice;
    cout<<endl;
    cout<<"Choices:"<<endl;
    cout<<"1. Enter solution process"<<endl;
    cout<<"2. Quit"<<endl<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice!="1"&&choice!="2")
    {
        cout<<endl<<"Invalid choice!"<<endl<<endl;
        cout<<"Please enter your choice again: ";
        cin>>choice;
    }
    while(choice!="2")
    {
        mat.clear();
        cons.clear();
        temp.clear();
        kaczmarz_solution.clear();
        ols_solution.clear();
        cout<<endl<<"Enter size of the matrix: ";
        cin>>n;
    
        cout<<endl<<"Do you want to generate an augmented matrix of "<<n<<" size?"<<endl;
        cout<<"Enter 1 for yes and anything else for no"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        if(choice=="1")
        {
            create_augmented_matrix(mat,cons,n);
            cout<<endl<<"The generated augmented matrix:"<<endl;
            print_aug_matrix(mat,cons);
            cout<<endl;
        }
        else{
            cout<<endl<<"Enter the augmented matrix:"<<endl;
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
        }
        
        cout<<endl<<"Enter number of iterations for kaczmarz operation: ";
        cin>>iter;
        kaczmarz_operation(mat,cons,kaczmarz_solution,iter);
        cout<<endl<<"Solution using Kaczmarz:"<<endl;
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
        // detect_outlier(kaczmarz_solution,ols_solution,outliers);
        if(difference_check(kaczmarz_solution,ols_solution)==true)
        {
            cout<<"There is 'significant differences' between the solutions of Kaczmarz method and OLS method ";
            cout<<"when using "<<iter<<" iterations"<<endl;
        }
        else
        {
            cout<<"There is 'no significant difference' between the solutions of Kaczmarz method and OLS method ";
            cout<<"when using "<<iter<<" iterations"<<endl;
        }
        cout<<endl;
        cout<<"Do you want to solve the same system for different iteration?"<<endl;
        cout<<"Enter 1 for yes. For no enter anything else."<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        while(choice=="1")
        {
            cout<<endl<<"Enter number of iterations for kaczmarz operation: ";
            cin>>iter;
            kaczmarz_solution.clear();
            kaczmarz_operation(mat,cons,kaczmarz_solution,iter);
            cout<<endl<<"Solution using Kaczmarz:"<<endl;
            for(auto s:kaczmarz_solution)
            {
                printf("%.3lf\n",s);
            }
            cout<<endl<<endl;
            cout<<"Solution using OLS:"<<endl;
            for(auto s:ols_solution)
            {
                printf("%.3lf\n",s);
            }
            cout<<endl<<endl;
            if(difference_check(kaczmarz_solution,ols_solution))
            {
                cout<<"There is 'significant differences' between the solutions of Kaczmarz method and OLS method ";
                cout<<"when using "<<iter<<" iterations"<<endl;
            }
            else
            {
                cout<<"There is 'no significant difference' between the solutions of Kaczmarz method and OLS method ";
                cout<<"when using "<<iter<<" iterations"<<endl;
            }
            cout<<endl<<endl;
            cout<<"Do you want to solve the same system for different iteration?"<<endl;
            cout<<"Enter 1 for yes. For no enter anything else."<<endl;
            cout<<endl<<"Enter your choice: ";
            cin>>choice;
        }
        cout<<endl<<"Choices:"<<endl;
        cout<<"1. Enter solution process"<<endl;
        cout<<"2. Quit"<<endl<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        while(choice!="1"&&choice!="2")
        {
            cout<<"Invalid choice!"<<endl;
            cout<<endl<<"Please enter your choice again: ";
            cin>>choice;
        }
    }
    
    return 0;
}
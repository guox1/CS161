//
//  main.cpp
//  lab 7 1
//
//  Created by Jacky on 2/23/15.
//  Copyright (c) 2015 lab 7 1. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
double f1(double x)               //f1(x)=1+x*x
{
    return(pow(x, 5) + 10);
}

double integral_rec(double(* fun)(double), double a, double b)
{
    double s,h;
    int i, N;
    cout << "N: ";
    cin >> N;
    cout << "a:";
    cin >> a;
    cout << "b: ";
    cin >> b;
    s = (* fun)(a);
    h = (b-a)/N;
    for(i = 1; i < N; i++)
        s += (*fun)(a+i*h);
    return(s*h);
}

double integral_tra(double(* fun)(double),double a,double b)      //求fun在a，b区间定积分
{
    double s,h;
    int i, N;
    cout << "N: ";
    cin >> N;
    cout << "a:";
    cin >> a;
    cout << "b: ";
    cin >> b;
    s=((* fun)(a)+(* fun)(b))/2.0;
    h=(b-a)/N;
    for(i=1;i<N;i++)
        s+=(*fun)(a+i*h);
    return(s*h);
}

int main()
{
    int choice;
    cout << "rec - 1, tra - 2, both - 3: ";
    cin >> choice;
    if (choice == 1){
        double y1, a, b;
        y1=integral_rec(f1,a,b);
        cout<<"sum =  "<<y1<<endl;
        
    }
    if (choice == 2){
        double y1, a, b;
        y1=integral_tra(f1,a,b);
        cout<<"sum =  "<<y1<<endl;
    }
    if (choice == 3){
        double y1, a, b;
        y1=integral_rec(f1,a,b);
        cout<<"sum =  "<<y1<<endl;
        y1=integral_tra(f1,a,b);
        cout<<"sum =  "<<y1<<endl;
    }
    return 0;
}
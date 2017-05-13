//
//  main.cpp
//  lab 7
//
//  Created by Jacky on 2/21/15.
//  Copyright (c) 2015 lab 7. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void integrate_rec(int sum1, int n, int a, int b, int i)
{
    int y, width;
    width = (b-a)/n;
    y = pow(i, 5) + 10;
    if (i < b)
    {
        integrate_rec(sum1 += y, n, a, b, i);
        i += width;
    }
    if (i >= b)
    {
        cout << "The area under x^5 + 10 between the interval you choose is: " << sum1 * width << endl;
    }
}

void integrate_tra(int sum2, int n, int a, int b, int i)
{
    int y, width;
    width = (b-a)/n;
    y = (pow(i, 5) + pow(i+width, 5) + 20)/2;
    if (i < b)
    {
        integrate_rec(sum2 += y, n, a, b, i);
        i += width;
    }
    if (i >= b)
    {
        cout << "The area under x^5 + 10 between the interval you choose is: " << sum2 * width << endl;
    }

}

int main()
{
    int choice;
    cout << "Would you like to calculeate the area using the rectangle, trapezoid, or both(1, 2, 3): ";
    cin >> choice;
    if (choice == 1) {
        int num_rec, a_rec, b_rec, sum1, i;
        cout << "how many number of rectangles you want to use: ";
        cin >> num_rec;
        cout << "what beginning x value you want to use: ";
        cin >> a_rec;
        cout << "what ending x value you want to use: ";
        cin >> b_rec;
        i = a_rec;
        integrate_rec(sum1, num_rec, a_rec, b_rec, i);
    }
    if (choice == 2){
        int num_rec, a_rec, b_rec, sum1, i;
        cout << "how many number of tra you want to use: ";
        cin >> num_rec;
        cout << "what beginning x value you want to use: ";
        cin >> a_rec;
        cout << "what ending x value you want to use: ";
        cin >> b_rec;
        i = a_rec;
        integrate_tra(sum1, num_rec, a_rec, b_rec, i);
    }
    if(choice ==3){
        int num_rec, a_rec, b_rec, sum1, i;
        cout << "how many number of rectangles you want to use: ";
        cin >> num_rec;
        cout << "what beginning x value you want to use: ";
        cin >> a_rec;
        cout << "what ending x value you want to use: ";
        cin >> b_rec;
        i = a_rec;
        integrate_rec(sum1, num_rec, a_rec, b_rec, i);
        cout << "how many number of tra you want to use: ";
        cin >> num_rec;
        cout << "what beginning x value you want to use: ";
        cin >> a_rec;
        cout << "what ending x value you want to use: ";
        cin >> b_rec;
        i = a_rec;
        integrate_tra(sum1, num_rec, a_rec, b_rec, i);
    }
    return 0;
}

//
//  main.cpp
//  cs 161
//
//  Created by Jacky on 1/18/15.
//  Copyright (c) 2015 assignment2. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

void base2(int num){
    if (num >= 2)
    { base2(num/2);
        cout << num % 2;
    }
    if (num < 2)
      cout << num;
}

int main() {
    string strInput1;
    cout << "Enter a string of Char: ";
    cin >> strInput1;
    int num = 0;
    int x = 0;
    cout << "The ASCII number in binary is: \n";
    while (x < strInput1.length()) {
        num = (int)strInput1.at(x); //change every Chars to an int num.
        base2(num); // get the binary every single time when the x < length of string of Chars.
        x++; //x=x+1
    }
    cout << " " << endl;
    cout << "Enter a string of 1s and 0s number: ";
    int strInput2;
    cin >> strInput2;
    int dec = 0;
    int last;
    int two = 1;
    while (strInput2 > 0){
        last = strInput2 % 10;
        dec = dec +last * two;
        two = two * 2;
        strInput2 = strInput2 / 10;
    }
    cout << "The ASCII value is: " << static_cast<char>(dec) << endl;
    return 0;
}
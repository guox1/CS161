/****************************************************************
 * ** Program: assignment3.cpp
 * ** Author: Xilun Guo
 * ** Date: 2/6/2015
 * ** Input: a string of characters, a string of numbers in binary
 * ** Output: a string of binary, a string of Characters
 * **************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

void dec_to_bin(int x); // in order to be called in ascii_to_dec() function.
/***************************
 pre-conditions: None
 post-conditions: None
 ****************************/
string get_user_input1(){
    string Input1;
    cout << "Enter a string of Char: ";
    getline(cin, Input1);
    return Input1;
}

int ascii(int x, string y)// doesn't do anything, just declare x and be called in ascii_to_dec() function.
{
    return (int)y.at(x);
}

void ascii_to_dec(){
    int num = 0;
    string Input1 = get_user_input1(); // call get_user_input1(), get the Input1.
    cout << "The Binary of your Input:";
    int x = 0;
    while (x < Input1.length()) {
        num = ascii(x, Input1); //change every Chars to an int num.
        cout << "0";
        if (num >= 2)
        {   dec_to_bin(num / 2);
            cout << num % 2;
        }
        if (num < 2)
            cout << num;
        x++; //x=x+1
    }
    
}

void dec_to_bin(int x){
    if (x >= 2)
    {   dec_to_bin(x / 2);
        cout << x % 2;
    }
    if (x < 2)
        cout << x;
}

/************************************************/

string get_user_input2(){
    string Input2;
    cout << "Enter a string of 1s and 0s number: ";
    getline(cin, Input2);
    return Input2;
}
/**************************************
 pre-conditions: 1s and 0s only.
 post-conditions: the length of Input2 % 8 is equal to 0, and after transfer to decimal have to be 0 < dec < 127.
 **************************************/
int check_bin_number(string Input2){
    int check = 1;
    for (int i = 0; i < Input2.length(); i++){ //checking if 1s and 0s only
        if (Input2.at(i) != '0' || Input2.at(i) != '1')
        {
            check = 0;
        }
        else
            check = 1;
    }
    if (Input2.length() % 8 != 0)
        check = 0;
    else
        check = 1;
    
    return check;
}

void bin_to_ascii(string Input2){
    cout << "The ASCII values is: ";
    int j = 0, position=0;
    while (j < Input2.length()){
        int dec = 0;
        for(int i = 7; i >= 0; i--){
            int number = (int)(Input2.at(position) - '0');//'0' or 48
            position++;
            dec += pow(2,i) * number;
        }
        j=j+8;
        cout << char(dec);
    }
}
int check_dec_number(string Input2){
    int j = 0, position=0, check = 1;
    while (j < Input2.length()){
        int dec = 0;
        for(int i = 7; i >= 0; i--){
            int number = (int)(Input2.at(position) - '0');//'0' or 48
            position++;
            dec += pow(2,i) * number;
        }
        if(dec < 0 || dec > 127){
            check = 0;
        }
        j=j+8;
    }
    return check;
}

int main(){
    //first part
    ascii_to_dec();
    cout << endl;
    
    //second part
    string Input2 = get_user_input2();
    int check = check_bin_number(Input2);
    if (check == 1)
        check = check_dec_number(Input2);
    while (check == 0){
        cout << "Invalid Input, ";
        Input2 = get_user_input2();
        check = check_bin_number(Input2);
        if (check == 1)
            check = check_dec_number(Input2);
    }
    bin_to_ascii(Input2);
    cout << endl;
    return 0;
}



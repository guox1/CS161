/*********************************************************
* ** Program: ssignment2.cpp
* ** Author: Xilun Guo
* ** Date: 1/26/2015
* ** Description: The first part is letting the user input a string of characters, then print a string of binary to the user.The second part is letting the user input a string of binary, then pring a string of characters back to the user.  Both of those two part are based on the ASCII values.
*  ** Input: characters, numbers in binary(1s and 0s only)
*  ** Output: a string of binary, a string of Characters
*  ******************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

void base2(int num){
    if (num >= 2)
    { base2(num/2);
        cout << num % 2;
    }
    if (num < 2)
        cout << num;
}

int CheckInput2(string Input2){
    int check = 0;
    for (int i = 0; i < Input2.length(); i++){ //checking if 1s and 0s only
        if (Input2.at(i) == '0' || Input2.at(i) == '1'){
            check = 1;//true
        }
        else
            check = 0;//falues
            
    }
    return check;
        
}

int main(){
    string Input1;
    cout << "Enter a string of Char: ";
    cin >> Input1;
    int num = 0;
    int x = 0;
    cout << "The ASCII number in binary is: ";
    while (x < Input1.length()) {
        num = (int)Input1.at(x); //change every Chars to an int num.
        cout << '0';
        base2(num); // get the binary every single time when the x < length of string of Chars.
        x++; //x=x+1
    }
    cout << " " << endl;
    cout << "Enter a string of 1s and 0s number: ";
    string Input2;//set the Input2 as string first in order to check if 1s and 0s only
    cin >> Input2;
    int check = CheckInput2(Input2);
    int j, position=0;
    if (check == 1){
    cout << "The ASCII values is: ";
        j = 0;
        while (j < Input2.length()){
            int dec = 0;
            for(int i = 7; i >= 0; i--){
                int number = (int)(Input2.at(position) - '0');//'0' or 48
                position++;
                dec += pow(2,i) * number;
                
                
            }
            cout << (char)(dec);
            j=j+8;
        }
	cout << "" << endl;
    }
    if (check == 0){
        while (check == 0){
            cout << "Invalid input, try again!" << endl;
            cout << "Enter a string of 1s and 0s number: ";
            string Input2;
            cin >> Input2;
            check = CheckInput2(Input2);//until get check = 1
            if (check == 1){
            cout << "The ASCII values is: ";
                j = 0;
                while (j < Input2.length()){
                    int dec = 0;
                    for (int i = 7; i >= 0; i--){
                        int number = (int)(Input2.at(position) - '0');
                        position++;
                        dec += pow(2,i) * number;
                    }
                    cout << (char)(dec);
                    j=j+8;
                }
            }
        cout << "" << endl;       
        }
    }
    return 0;
}

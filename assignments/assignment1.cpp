/****************************************************** 
 * ** Program: assignment1.cpp
 * ** Author: Xilun Guo
 * ** Date: 1/16/2015 
 * ** Description: Finding the largest and smallest number of short, int, and long, both signed and unsigned. Printing the largest and smallest number of short, int, and long, both signed and unsigned from macros. Changing the Char from user input using ASCII value as a decimal, binary, and hexadecimal.
 * ** Input: Character
 * ** Output: The largest and smallest number of short, int, and long, both signed and unsigned. A decimal, binary, and hexadecimal.
 * ******************************************************/ 

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void y(int x){
  if (x >= 2)
  { y(x/2);
    cout << x%2;   
  }
  if (x < 2)
    cout << x;
}

int main(){
  cout << sizeof(short) << endl;
  int nShortSpot = sizeof(short) * 8;
  cout << "Short Signed maximum: ";
  cout << pow(2, nShortSpot-1)-1 << endl;
  cout << "Short Signed maximum printed from the macros: ";
  cout << SHRT_MAX << endl;
  cout << "Short Signed minimum: ";
  cout << pow(-2, nShortSpot-1) << endl;
  cout << "Short Signed minimum printed from the macros: ";
  cout << SHRT_MIN << endl;
  cout << "Short Unsigned maximum: ";
  cout << pow(2, nShortSpot)-1 << endl;
  cout << "Short Unsigned maximum printed from the macros: ";
  cout << USHRT_MAX << endl;
  cout << "Short Unsigned minimum: 0" << endl;

  cout << sizeof(int) << endl;
  int nIntSpot = sizeof(int) * 8;
  cout << "Int Signed maximum: ";
  cout << pow(2, nIntSpot-1)-1 << endl;
  cout << "Int Signed maximum printed from the macros: ";
  cout << INT_MAX << endl;
  cout << "Int Signed minimum: ";
  cout << pow(-2, nIntSpot-1) << endl;
  cout << "Int Signed minimum printed from the macros: ";
  cout << INT_MIN << endl;
  cout << "Int Unsigned maximum: ";
  cout << pow(2, nIntSpot)-1 << endl;
  cout << "Int Unsigned maximum printed from the macros: ";
  cout << UINT_MAX << endl;
  cout << "Int Unsigned minimum: 0" << endl;
  
  cout << sizeof(long) << endl;
  int nLongSpot = sizeof(long) * 8;
  cout << "Long Signed maximum: ";
  cout << pow(2, nLongSpot-1)-1 << endl;
  cout << "Long Signed maximum printed from the macros: ";
  cout << LONG_MAX << endl;
  cout << "Long Signed minimum: ";
  cout << pow(-2, nLongSpot-1) << endl;
  cout << "Long Signed minimum printed from the macros: ";
  cout << LONG_MIN << endl;
  cout << "Long Unsigned maximum: ";
  cout << pow(2, nLongSpot) << endl;
  cout << "Long Unsigned maximum printed from the macros: ";
  cout << ULONG_MAX << endl;
  cout << "Long Unsigned minimum: 0" << endl;  
  
  cout << "Enter a Char: ";
  char x;
  cin >> x;  
  cout << "The ASCII number in decimal is: ";
  cout << (int)x << endl;
  cout << "The ASCII number in binary is:  ";
  y(x);
  cout << endl;
  cout << "The ASCII number in hexadecimal is: ";
  cout << hex << (int)x << endl;
  cout << dec;
 
  return 0;
}


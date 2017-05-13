//
//  main.cpp
//  lab5
//
//  Created by Jacky on 2/8/15.
//  Copyright (c) 2015 labs. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void N4(int x)
{
    for (int i = 1; i <= x; i++)
    {
        cout << "M";
    }
}

void N3(int x)
{
    if (x >= 1 && x < 4)
    {
        for (int i = 1; i <= x; i++)
            cout << "C";
    }
    else if (x == 4)
        cout << "CD";
    else if (x >= 5 && x < 9)
    {
        cout << "D";
        for (int i = 5; i < x; i++)
            cout << "C";
    }
    else if (x == 9)
        cout << "CM";
}

void N2(int x)
{
    if(x >= 1 && x < 4)
    {
        for (int i = 1; i <= x; i++)
        cout << "X";
    }
    else if (x == 4)
        cout << "XL";
    else if (x >= 5 && x < 9)
    {
        cout << "L";
        for (int i = 5; i < x; i++)
            cout << "X";
    }
    else if (x == 9)
        cout << "XC";
}

void N1 (int x)
{
    if (x >= 1 && x < 4)
    {
        for (int i = 1; i <= x; i++)
        cout << "I";
    }
    else if (x == 4)
        cout << "IV";
    else if (x >= 5 && x < 9)
    {
        cout << "V";
        for (int i = 5; i < x; i++)
            cout << "I";
    }
    else if (x == 9)
        cout << "IX";
}

void dec_to_rn(int ndigit, string strInput1)
{
    if (ndigit == 4)
    {
        N4(static_cast<int>(strInput1.at(0)) - 48);
        N3(static_cast<int>(strInput1.at(1)) - 48);
        N2(static_cast<int>(strInput1.at(2)) - 48);
        N1(static_cast<int>(strInput1.at(3)) - 48);
    }
    if (ndigit == 3)
    {
        N3(static_cast<int>(strInput1.at(0)) - 48);
        N2(static_cast<int>(strInput1.at(1)) - 48);
        N1(static_cast<int>(strInput1.at(2)) - 48);
    }
    if (ndigit == 2)
    {
        N2(static_cast<int>(strInput1.at(0)) - 48);
        N1(static_cast<int>(strInput1.at(1)) - 48);
    }
    if (ndigit == 1)
    {
        N1(static_cast<int>(strInput1.at(0)) - 48);
    }
        
}

int ValueR(char x)
{
    switch(x)
    {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
    }
}

void rn_to_dec (string strInput2, unsigned long length)
{
    int nDec = 0;
    for (int i = 0; i < length; i++)
    {
        if(i + 1 < length)
        {
            int nCurrent = ValueR(strInput2.at(i));
            int nNext = ValueR(strInput2.at(i + 1));
            if (nCurrent >= nNext)
                nDec += nCurrent;
            else
                nDec -= nCurrent;
        }
        else if (i + 1 == length)
        {
            char chChange = strInput2.at(i);
            int nCurrent = ValueR(chChange);
            nDec += nCurrent;
        }
    }
    cout << nDec << endl;
}

int check_decimal(string x)
{
    int length = static_cast<int>(x.length()), y = 0;
    for (int iii = 0; iii < length; iii++)
    {
        if (x.at(iii) != '1' && x.at(iii) != '2' && x.at(iii) != '3' && x.at(iii) != '4' && x.at(iii) != '5' && x.at(iii) != '6' && x.at(iii) != '7' && x.at(iii) != '8' && x.at(iii) != '9' && x.at(iii) != '0')
        {
            cerr << "ERROR, NOT DECIMAL! \n";
            return 0;
        }
    }
    for (int iii = 0, jjj = length; iii < length; iii++, jjj--)
    {
        y += (static_cast<int>(x.at(iii)) - 48) * pow(10, jjj - 1);
    }
    if (y <= 0 || y >= 4000)
    {
        cerr << "ERROR, NOT IN RANGE! \n";
        return 0;
    }
    return 1;
}

int check_ro(string x)
{
    int length = static_cast<int>(x.length());
    for (int iii = 0; iii < length; iii++)
    {
        if (x.at(iii) != 'I' && x.at(iii) != 'V' && x.at(iii) != 'X' && x.at(iii) != 'L' && x.at(iii) != 'C' && x.at(iii) != 'D' && x.at(iii) != 'M')
        {
            cerr << "ERROR, NOT VALID ROMAN NUMERAL! \n";
            return 0;
        }
    }
    return 1;
}
    /*for (int iii = 0; iii < length; iii++)
    {
        if (length - iii >= 4)
        {
            if (x.at(iii) == x.at(iii + 1) && x.at(iii + 1) == x.at(iii + 2) && x.at(iii + 2) == x.at(iii + 3))
            {
                cerr << "ERROR, 3 IN A ROW AT MOST! \n";
                return 0;
            }
        }
    }
    for (int iii = 0; iii < length; iii++)
    {
        if(iii + 1 < length)
        {
            int x1 =ValueR(x.at(iii));
            int x2 = ValueR(x.at(iii + 1));
            if (x1 < x2 && x1 != 1 && x1 != 10 && x1 != 100)
            {
                cerr << "ERROR, ONLY I, X, C CAN BE SUBSTRACT! \n";
                return 0;
            }
            if (x2 > 10 * x1)
            {
                cerr << "ERROR, CAN'T SUBSTRACT A SMALL NUMBER: \n";
                return 0;
            }
        }
    }
    return 1;
}
*/
int main()
{
    /*Convert Decimal to Roman Numeral*/
    string strInput1;
    int nCheck1;
    do
    {
        cout << "Enter a decimal number: ";
        cin >> strInput1;
        nCheck1 = check_decimal(strInput1);
    }while (nCheck1 == 0);
    int ndigit = static_cast<int>(strInput1.length());
    cout << "The Roman Numeral of your input is: ";
    dec_to_rn(ndigit, strInput1);
    cout << endl;
    
    /*Convert Roman Numeral to Decimal*/
    string strInput2;
    //cout << "Enter a Roman Numeral: ";
    //cin >> strInput2;
    int nCheck2;
    do
    {
        cout << "Enter a Roman Numeral: ";
        cin >> strInput2;
        nCheck2 = check_ro(strInput2);
    }while (nCheck2 == 0);

    unsigned long length = strInput2. length();
    
    cout << "The Decimal Numer of your input is: ";
    rn_to_dec(strInput2, length);
    
    return 0;
}

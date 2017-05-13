//  main.cpp
//  CS 161 Assignment#5
//
//  Created by Xilun on 3/5/15.
//  Copyright (c) 2015 Xilun.
//

/*********************************************************************
 ** Program Filename: Assignment#5
 ** Author: Xilun Guo
 ** Date: 03/04/2015
 ** Description: Finding The greatest Production in a Matrix
 ** Input: Matrix's rows and cols
 ** Output: The greatest Product, the Production and the shape
 *********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

/*********************************************************************
 ** Function: struct
 ** Description: Mixed types
 ** Parameters: x, y, &Max, &Position_x, &Position_y, &strShape, nR, nC
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

struct doc_rec
{
    int x, y, Max, nCompare, Position_x, Position_y, nR, nC;
    string strShape;
};


/*********************************************************************
 ** Function: Comparing using Horizontal
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

/**************** 横着对比 ********************/

void gp_Horizontal(int **&nArray, doc_rec *corvallis)
{
    corvallis->strShape="";
    corvallis->Max = 0;
    for (int i = 0; i < corvallis->x; i++)
    {
        for (int j = 0; j < (corvallis->y - 3); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i][j+2] * nArray[i][j+3];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal";
            }
        }
    }
}
/*********************************************************************
 ** Function: Comparing using Verticle
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

/******************* 竖着对比 ******************/

void gp_Verticle(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-3); i++)
    {
        for (int j = 0; j < corvallis->y; j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i+2][j] * nArray[i+3][j];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Verticle";
            }
        }
    }
    
}
/*********************************************************************
 ** Function: Comparing using right diagonal
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

/****************** 从右往左斜 ******************/

void gp_Right_Diagonal(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x - 3); i++)
    {
        for (int j = 0; j < (corvallis->y - 3); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j+1] * nArray[i+2][j+2] * nArray[i+3][j+3];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Right Diagonal";
            }
        }
    }
}

/*********************************************************************
 ** Function: Comparing using left diagonal
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

/***************** 从左往右斜 *********************/

void gp_Left_Diagonal(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x - 3); i++)
    {
        for (int j = 3; j < corvallis->y; j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j-1] * nArray[i+2][j-2] * nArray[i+3][j-3];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Left Diagonal";
            }
        }
    }
}

/*********************************************************************
 ** Function: Comparing using box
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

/****************** 正方形 *********************/

void gp_Box(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x - 1); i++)
    {
        for (int j = 0; j < (corvallis->y - 1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i][j+1] * nArray[i+1][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Box";
            }
        }
    }
}

/*********************************************************************
 ** Function: Comparing using zig-zag
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_Z1(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x - 1); i++)
    {
        for (int j = 0; j < (corvallis->y - 2); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i+1][j+1] * nArray[i+1][j+2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal Z from left to right";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using zig-zag
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_Z2(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x - 1); i++)
    {
        for (int j = 2; j < corvallis->y; j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j-1] * nArray[i+1][j-1] * nArray[i+1][j-2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal Z from right to left";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using zig-zag
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_Z3(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-2); i++)
    {
        for (int j = 0; j < (corvallis->y - 1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i+1][j+1] * nArray[i+2][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Verticle Z from left to right";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using zig-zag
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_Z4(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-2); i++)
    {
        for (int j = 1; j < corvallis->y; j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i+1][j-1] * nArray[i+2][j-1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Verticle Z from right to left";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L1(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-1); i++)
    {
        for (int j = 0; j < (corvallis->y-2); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i][j+2] * nArray[i+1][j+2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal L1, short line on the right down side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L2(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-1); i++)
    {
        for (int j = 0; j < (corvallis->y-2); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i+1][j+1] * nArray[i+1][j+2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal L22, short line on the left up side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L3(int **&nArray, doc_rec *corvallis)
{
    for (int i = 1; i < corvallis->x; i++)
    {
        for (int j = 0; j < (corvallis->y-2); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i-1][j] * nArray[i-1][j+1] * nArray[i-1][j+2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal L3, short line on the left down side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L4(int **&nArray, doc_rec *corvallis)
{
    for (int i = 1; i < corvallis->x; i++)
    {
        for (int j = 0; j < (corvallis->y-2); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i][j+2] * nArray[i-1][j+2];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Horizontal L4, short line on the right up side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L5(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-2); i++)
    {
        for (int j = 0; j < (corvallis->y-1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i+1][j] * nArray[i+2][j] * nArray[i+2][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Vertical L5, short line on the right down side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L6(int **&nArray, doc_rec *corvallis)
{
    for (int i = 2; i < corvallis->x; i++)
    {
        for (int j = 0; j < (corvallis->y-1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i-1][j+1] * nArray[i-2][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Vertical L6, short line on the left down side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L7(int **&nArray, doc_rec *corvallis)
{
    for (int i = 2; i < corvallis->x; i++)
    {
        for (int j = 0; j < (corvallis->y-1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i-1][j] * nArray[i-2][j] * nArray[i-2][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Vertical L7, short line on the right up side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: Comparing using L shape
 ** Description: Comparing with the Max, if greater than Max, than Max gets the nCompare.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void gp_L8(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < (corvallis->x-2); i++)
    {
        for (int j = 0; j < (corvallis->y-1); j++)
        {
            corvallis->nR = i;
            corvallis->nC = j;
            corvallis->nCompare = nArray[i][j] * nArray[i][j+1] * nArray[i+1][j+1] * nArray[i+2][j+1];
            if(corvallis->nCompare > corvallis->Max)
            {
                corvallis->Max = corvallis->nCompare;
                corvallis->Position_x = corvallis->nR;
                corvallis->Position_y = corvallis->nC;
                corvallis->strShape = "Vertical L8, short line on the left up side";
            }
        }
    }
    
}

/*********************************************************************
 ** Function: get input of rows
 ** Parameters: input1
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

string get_input1()
{
    string input1;
    cout << "Enter Number of Rows: ";
    getline(cin, input1);
    return input1;
}

/*********************************************************************
 ** Function: check input1 if is int
 ** Parameters: input1
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int check_input1(string input1)
{
    int check = 1;
    for(int i = 0; i < input1.length(); i++)
    {
        if(input1[i] < '0' || input1[i] > '9')
        {
            check = 0;
        }
    }
    
    return check;
}

/*********************************************************************
 ** Function: get input of cols
 ** Parameters: input2
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
string get_input2()
{
    string input2;
    cout << "Enter Number of Cols: ";
    getline(cin, input2);
    return input2;
}

/*********************************************************************
 ** Function: check input2 if is int
 ** Parameters: input1
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int check_input2(string input2)
{
    int check = 1;
    for(int i = 0; i < input2.length(); i++)
    {
        if(input2[i] < '0' || input2[i] > '9')
        {
            check = 0;
        }
    }
    
    return check;
}

/*********************************************************************
 ** Function: creat and print 2D array
 ** Description: creating and printing 2D array if user don't use text file.
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions: x and y are int
 ** Post-Conditions:
 *********************************************************************/

void create_array(int **&nArray, doc_rec *corvallis)
{
    string input1 = get_input1();
    int check = check_input1(input1);
    while(check == 0)
    {
        cout << "Bad Number!" << endl;
        input1 = get_input1();
        check = check_input1(input1);
    }
    
    string input2 = get_input2();
    check = check_input2(input2);
    while(check == 0)
    {
        cout << "Bad Number!" << endl;
        input2 = get_input2();
        check = check_input2(input2);
    }
   
    stringstream ss(input1);
    ss >> corvallis->x;
    stringstream s(input2);
    s >>corvallis->y;
    

    nArray = new int *[corvallis->x];
    
    srand(time(NULL));
    for (int i = 0; i < corvallis->x; i++)
    {
        nArray[i] = new int [corvallis->y];
        for (int j = 0; j < corvallis->y; j++)
        {
	    int num = 0;
            num = rand() % 50 + 1;
            
            nArray[i][j] = num;
            
            cout << num << " ";
            
            if ((j + 1) % corvallis->y == 0)
            {
                cout << endl;
            }
        }
    }
}

/*********************************************************************
 ** Function: Printing Matrix
 ** Description: Printing Matrix if user use text file
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void Print_Matrix(int **&nArray, doc_rec *corvallis)
{
    for (int i = 0; i < corvallis->x; i++)
    {
        for (int j = 0; j < corvallis->y; j++)
        {
            cout << nArray[i][j] << " ";
        }
        cout << endl;
    }
}

/*********************************************************************
 ** Function: get text file info
 ** Description: get the rows and cols from text file, and get the matrix also
 ** Parameters: **nArray, doc_rec
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void test_file(int **&nArray, doc_rec *corvallis)
{
    string strShape;
    cin >> corvallis->x;
    cin >> corvallis->y;
    
    nArray = new int *[corvallis->x];
    for(int i = 0; i < corvallis->x; i++){
        nArray[i] = new int [corvallis->y];
        for(int j = 0; j < corvallis->y; j++){
            cin >> nArray[i][j];
        }
    }
}


int main(int argc, const char * argv[])
{
    int **nArray;
    struct doc_rec corvallis;
    if (argc==2 && !strcmp(argv[1], "-test"))
    {   test_file(*&nArray, &corvallis);
        Print_Matrix(*&nArray, &corvallis);
    }
    else if (argc==2)
    {   cout << "Bad argument or you type -test wrong!" << endl;
        exit(0);
    }
    else
        create_array(*&nArray, &corvallis);
    gp_Horizontal(*&nArray, &corvallis);
    gp_Verticle(*&nArray, &corvallis);
    gp_Right_Diagonal(*&nArray, &corvallis);
    gp_Left_Diagonal(*&nArray, &corvallis);
    gp_Box(*&nArray, &corvallis);
   
    gp_Z1(*&nArray, &corvallis);
    gp_Z2(*&nArray, &corvallis);
    gp_Z3(*&nArray, &corvallis);
    gp_Z4(*&nArray, &corvallis);
    gp_L1(*&nArray, &corvallis);
    gp_L2(*&nArray, &corvallis);
    gp_L3(*&nArray, &corvallis);
    gp_L4(*&nArray, &corvallis);
    gp_L5(*&nArray, &corvallis);
    gp_L6(*&nArray, &corvallis);
    gp_L7(*&nArray, &corvallis);
    gp_L8(*&nArray, &corvallis);

    cout << "The greatest product of any four adjacent numbers is: " << corvallis.Max << endl;
    cout << "Position in Rows: " << corvallis.Position_x+1 << " Position in Cols: " << corvallis.Position_y+1 << endl;
    cout << "Shape: " << corvallis.strShape << endl;
    delete [] nArray; //delete at the end when you don't use it anymore.
    return 0;
}

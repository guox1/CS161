//
//  main.cpp
//  lab 8
//
//  Created by Jacky on 3/1/15.
//  Copyright (c) 2015 lab 8. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void create_array(int nRows, int nCols, int *nArray)
{
    for (int i(0); i < nRows * nCols; ++i)
    {
        int num = 0;
        num = rand() % 50 + 1;
        
        nArray[i] = num;
        
        cout << num << " ";
        
        if ((i + 1) % nCols == 0)
        {
            cout << endl;
        }
    }
}

void find_greatest_product(int *nArray, int x, int y)
{
    int nMax = 0;
    
    for (int i(0); i < x; ++i)
    {
        int nCompare = 0;
        nCompare = nArray[i] * nArray[i + 1] * nArray[i * y] * nArray[(i * y) + 1];
        if(nCompare > nMax)
        {
            nMax = nCompare;
        }
    }
    cout << "Max Prod: " << nMax << endl;
}

int main(int argc, const char * argv[])
{
    int nRows, nCols;
    cout << "Please enter numbers of rows: ";
    cin >> nRows;
    
    cout << "Please enter numbers of cols: ";
    cin >> nCols;
    
    int nNum = nRows * nCols;
    
    int *nArray = new int[nNum];
    
    srand(time(NULL));
    
    create_array(nRows, nCols, nArray);
    
    find_greatest_product(nArray, nRows, nCols);
    
    delete [] nArray;
    
    return 0;
}

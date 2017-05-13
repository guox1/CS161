#include <iostream>
using namespace std;

const int NUM_COLS = 3;
const int NUM_ROWS = 3;

void towers(int, int [][NUM_COLS], int, int, int);
void Print_Array(int [][NUM_COLS], int);

int main() {
    int table1[NUM_ROWS][NUM_COLS] = { {1, 0, 0},
                                        {2, 0, 0},
                                     {3, 0, 0} };
    Print_Array(table1, 3);
    cout << "-----" << endl;
    towers(3, table1, 0, 2, 1);
    cout << "DONE" << endl;
    return 0;
}

void Print_Array(int array[][NUM_COLS], int numRows)
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << array[row][col] << " ";
        }
        cout << endl;
    }
}

void move(int array[][NUM_COLS], int from_col, int to_col)
{
    int rows = 3, row1 = -1, row2 = -1;
    for (int i = 0; i < rows; i++)
    {
        if(array[i][from_col] != 0 && row1 == -1)
            row1 = i;
        if(array[i][to_col] != 0 && row2 == -1)
            row2 = i-1;
    }
    if (row2 == -1)
        row2 = rows - 1;
    cout << "from col: " << from_col << "    to col: " << to_col << endl;
    cout << "row1: " << row1 << "   row2: " << row2 << endl;
    array[row2][to_col] = array[row1][from_col];
    array[row1][from_col] = 0;
}
void towers(int disks, int array[][NUM_COLS], int from_col, int to_col, int spare)
{
    int numRows = 3;

    if(disks >= 1)
    {
        towers(disks-1, array, from_col, spare, to_col);
        
        move(array, from_col, to_col);
        Print_Array(array, numRows);

        cout << "-----" << endl;
        towers(disks-1, array, spare, to_col, from_col);
    }
}

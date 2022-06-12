#include <iostream>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

char** CreateField(int& rows, int& colums) {

    /// Create 

    char** field = new char* [rows];
    for (int i = 0; i < rows; i++) {
        field[i] = new char[colums];
    }
    return field;
}

void FillField(char** field, int& rows, int& colums) {
    /// Fill

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            field[i][j] = '_';
        }
    }
}

void OutputField(char** field, int& rows, int& colums){
    /// Output

    cout << " ";
    for (int i = 1; i < colums + 1; i++) {
        cout <<" "<< i;
    }

    cout << endl; 

    for (int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < colums; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteField(char** field, int& rows, int& colums) {
    
    /// Delete
    
    for (int i = 0; i < rows; i++) {
        delete[] field[i];
    }
    delete[] field;
}

void InfillGamerField(char** field, int& rows, int& colums, boolean& gamer) {

    int row, column;
    bool flag = true;
    
    while (flag) {
        cout << "Please enter row, after it - column : ";
        cin >> row >> column;
        
        if (row <= rows && column <= colums) {
            if (field[row - 1][column - 1] == '_') {

                field[row - 1][column - 1] = 'X';

                if ((row != rows)
                    && (column != colums)
                    && (row != 2 && column != 2)
                    && (row != 1)
                    && (column != 1)
                    && (row != rows)
                    && (column != colums))
                {
                    if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                        (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                        (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                        (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                        (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X') ||//CROSS HIGH lEFT

                        (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X') ||//CROSS  UNDER LEFT

                        (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X') ||//CROSS HIGH RIGHT

                        (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X') ||//CROSS  UNDER RIGHT

                        (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) + 1][(column - 1) + 1] == 'X') ||//CROSS lEFT MIDDLE

                        (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) - 1][(column - 1) + 1] == 'X'))//CROSS  RIGHT MIDDLE

                    {

                        flag = false;

                        gamer = true;

                        break;

                    }
                }


                /// 
                /// Exeptions
                /// 
                ///1
                else if ((row == 1 && column == 1)) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                        (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                        (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X'))//CROSS  UNDER RIGHT
                    {

                        flag = false;

                        gamer = true;

                        break;
                    }
                }



                /// 
                /// 2
                //

                else if (row == 2 && column == 2) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                        (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                        (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X') ||//CROSS  UNDER RIGHT

                        (field[2][0] == 'X' && field[0][2] == 'X') ||//CROSS lEFT MIDDLE

                        (field[0][0] == 'X' && field[2][2] == 'X'))//CROSS  RIGHT MIDDLE
                    {
                        flag = false;

                        gamer = true;

                        break;

                    }
                }
                /// 
                /// High Line
                /// 
                else if (row == 1) {
                    if (column == colums) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }
                    }
                    else if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X') ||//CROSS  UNDER LEFT

                            (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }
                    }
                    else if (column == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }
                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }


                    }

                }

                /// 
                /// Left line
                //

                else if (column == 1) {

                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                            (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X') ||//CROSS  UNDER RIGHT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X') ||//CROSS HIGH RIGHT

                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X'))//ROW -
                        {
                            flag = false;

                            gamer = true;

                            break;
                        }
                    }

                    else if (row == 2) {
                        if (
                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+
                            (field[(row - 1) + 1][(column - 1) + 1] == 'X' && field[(row - 1) + 2][(column - 1) + 2] == 'X') ||//CROSS  UNDER RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X'))//ROW MIDDLE
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }

                    else if (row == rows - 1) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X') ||//CROSS HIGH RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X'))//ROW MIDDLE
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == rows) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -
                            (field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X'))//CROSS HIGH RIGHT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                }
            
                /// lower line

                else if (row == rows) {
                    if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-
                            
                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X') ||//CROSS HIGH lEFT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            gamer = true;

                            break;
                        }

                    }
                    else if (column == 2) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'X' && field[(row - 1)][(column - 1) + 2] == 'X') ||//COLUMN+

                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) + 1] == 'X' && field[(row - 1) - 2][(column - 1) + 2] == 'X'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            gamer = true;

                            break;
                        }

                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) + 1] == 'X') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X'))//CROSS HIGH lEFT

                        {
                            flag = false;

                            gamer = true;;

                            break;
                        }
                    }
                    else if (column == colums) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }
                    }
                }

                /// 
                /// Right line
                //


                else if ( column == colums) {
                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE
    
                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X') ||//CROSS HIGH lEFT

                            (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X') )//CROSS  UNDER LEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }

                    }
                    else if (row == (rows - 1)) {
                        if (
                            (field[(row - 1) - 1][(column - 1)] == 'X' && field[(row - 1) - 2][(column - 1)] == 'X') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'X' && field[(row - 1) - 2][(column - 1) - 2] == 'X'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }

                    }
                    else if (row == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) + 2][(column - 1)] == 'X') ||//ROW +

                            (field[(row - 1) + 1][(column - 1)] == 'X' && field[(row - 1) - 1][(column - 1)] == 'X') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'X' && field[(row - 1)][(column - 1) - 2] == 'X') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'X' && field[(row - 1) + 2][(column - 1) - 2] == 'X'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            gamer = true;

                            break;

                        }
                    }
                }

                break;
            }
            else {
                cout << "\n this element is filled \n";
            }
        }
        else {
            cout << "\n Does not exist \n";
        }
        cout << "\n Try pls another ;) \n" << endl;
    }
}
void InFillComputerLevel1Field(char** field, int& rows, int& colums, boolean& computer) {
    srand(time(NULL));
    boolean flag = true;
    int row;
    int column;
    while (flag) {
        row = (rand() % rows ) + 1;
        column = (rand() % colums ) + 1;
        if (row <= rows && column <= colums) {
            if (field[row - 1][column - 1] == '_') {

                field[row - 1][column - 1] = 'O';

                if ((row != rows)
                    && (column != colums)
                    && (row != 2 && column != 2)
                    && (row != 1)
                    && (column != 1)
                    && (row != rows)
                    && (column != colums))
                {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                        (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                        (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                        (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O') ||//CROSS  UNDER LEFT

                        (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                        (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) + 1][(column - 1) + 1] == 'O') ||//CROSS lEFT MIDDLE

                        (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) - 1][(column - 1) + 1] == 'O'))//CROSS  RIGHT MIDDLE

                    {

                        flag = false;

                        computer = true;

                        break;

                    }
                }


                /// 
                /// Exeptions
                /// 
                ///1
                else if ((row == 1 && column == 1)) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT
                    {

                        flag = false;

                        computer = true;

                        break;
                    }
                }



                /// 
                /// 2
                //

                else if (row == 2 && column == 2) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                        (field[2][0] == 'X' && field[0][2] == 'O') ||//CROSS lEFT MIDDLE

                        (field[0][0] == 'X' && field[2][2] == 'O'))//CROSS  RIGHT MIDDLE
                    {
                        flag = false;

                        computer = true;

                        break;

                    }
                }
                /// 
                /// High Line
                /// 
                else if (row == 1) {
                    if (column == colums) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O') ||//CROSS  UNDER LEFT

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }


                    }

                }

                /// 
                /// Left line
                //

                else if (column == 1) {

                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O'))//ROW -
                        {
                            flag = false;

                            computer = true;

                            break;
                        }
                    }

                    else if (row == 2) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -
                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+
                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O'))//ROW MIDDLE
                        {
                            flag = false;

                            computer = true;

                            break;

                        }
                    }

                    else if (row == rows - 1) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O'))//ROW MIDDLE
                        {
                            flag = false;

                            computer = true;

                            break;
                        }
                    }
                    else if ((row == rows && column == 1)) {

                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {

                            flag = false;

                            computer = true;;

                            break;

                        }

                    }
                }

                /// 
                /// lower line
                //

                else if (row == rows) {
                    if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-
                        
                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            computer = true;

                            break;
                        }

                    }
                    else if (column == 2) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            computer = true;

                            break;
                        }

                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {
                            flag = false;

                            computer = true;;

                            break;
                        }
                    }
                    else if (column == colums) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                }

                /// 
                /// Right line
                //


                else if (column == colums) {
                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }

                    }
                    else if (row == (rows - 1)) {
                        if (
                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }

                    }
                    else if (row == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                }

                break;
            }
        }
        else {
            cout << "\n Does not exist \n";
        }
        cout << "\n Try pls another ;) \n" << endl;
    
    }
}

void InFillComputerLevel2Field(char** field, int& rows, int& colums, boolean& computer) {
    srand(time(NULL));
    boolean flag = true;
    boolean flagtest = true;

    int rowtest;
    int columntest;
    int row;
    int column;

    while (flag) {
        while (flagtest) {
            rowtest = (rand() % rows) + 1;
            columntest = (rand() % colums) + 1;
            

            if (field[rowtest - 1][columntest - 1] == '_') {
                if (rowtest == 1) {
                    if (columntest == 1) {
                        if (field[1][0] == 'X' || field[0][1] == 'X' || field[1][1] == 'X') {

                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;

                        }
                    }
                    else if (columntest == colums) {
                        if (field[1][columntest-1] == 'X' || field[0][(columntest-1) - 1] == 'X' || field[1][(columntest-1) - 1] == 'X') {

                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;

                        }
                    }
                    else {
                        if (field[0][(columntest - 1) - 1] == 'X' || field[0][(columntest - 1) + 1] == 'X' || field[1][(columntest - 1) - 1] == 'X' || field[1][(columntest - 1) + 1] == 'X'
                            || field[1][(columntest - 1)] == 'X') {
                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;
                        }
                    }
                }
                else if (columntest == 1) {
                    if (rowtest == rows) {
                        if (field[(rowtest-1) - 1][0] == 'X' || field[(rowtest-1) - 1][1] == 'X' || field[rowtest-1][1] == 'X') {
                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;
                        }
                    }
                    else {
                        if (field[(rowtest - 1) - 1][0] == 'X' || field[(rowtest - 1) - 1][(columntest - 1) + 1] == 'X' || field[rowtest - 1][(columntest - 1) + 1] == 'X'
                            || (field[(rowtest - 1) + 1][0] == 'X' || field[(rowtest - 1) + 1][(columntest - 1) + 1] == 'X')) {
                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;
                        }
                    }
                }
                else if (rowtest == rows) {
                    if (columntest == colums) {
                        if (field[(rowtest - 1) - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) - 1][(columntest - 1)] == 'X' 
                            || (field[(rowtest - 1)][(columntest - 1) - 1] == 'X')) {
                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;
                        }
                    }
                    else {
                        if (field[(rowtest - 1) - 1][(columntest-1) - 1] == 'X' || field[(rowtest - 1) - 1][(columntest - 1) + 1] == 'X' 
                            || field[rowtest - 1][(columntest - 1) + 1] == 'X'
                            || (field[(rowtest - 1) - 1][(columntest - 1)] == 'X' || field[(rowtest - 1) - 1][(columntest - 1) - 1] == 'X')) {
                            row = rowtest;
                            column = columntest;
                            flagtest = false;
                            break;
                        }

                    }
                }
                else if (columntest == colums) {
                    if (field[(rowtest - 1) - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) - 1][columntest - 1] == 'X' 
                        || field[(rowtest - 1) + 1][columntest - 1] == 'X'
                        || (field[rowtest - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) + 1][(columntest - 1) - 1] == 'X')) {
                        row = rowtest;
                        column = columntest;
                        flagtest = false;
                        break;
                    }
                }
                else {
                    if (field[(rowtest - 1) - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) - 1][columntest - 1] == 'X' 
                        || field[(rowtest - 1) + 1][columntest - 1] == 'X'
                        || field[rowtest - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) + 1][(columntest - 1) - 1] == 'X' 
                        || field[(rowtest - 1) + 1][(columntest - 1) + 1] == 'X' || field[rowtest - 1][(columntest - 1) + 1] == 'X' 
                        || field[(rowtest - 1) - 1][(columntest - 1) + 1] == 'X') {
                        row = rowtest;
                        column = columntest;
                        flagtest = false;
                        break;
                    }
                }
            }
        }
        

        if (row <= rows && column <= colums) {
            if (field[row - 1][column - 1] == '_') {

                field[row - 1][column - 1] = 'O';

                if ((row != rows)
                    && (column != colums)
                    && (row != 2 && column != 2)
                    && (row != 1)
                    && (column != 1)
                    && (row != rows)
                    && (column != colums))
                {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                        (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                        (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                        (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O') ||//CROSS  UNDER LEFT

                        (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                        (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) + 1][(column - 1) + 1] == 'O') ||//CROSS lEFT MIDDLE

                        (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) - 1][(column - 1) + 1] == 'O'))//CROSS  RIGHT MIDDLE

                    {

                        flag = false;

                        computer = true;

                        break;

                    }
                }


                /// 
                /// Exeptions
                /// 
                ///1
                else if ((row == 1 && column == 1)) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT
                    {

                        flag = false;

                        computer = true;

                        break;
                    }
                }



                /// 
                /// 2
                //

                else if (row == 2 && column == 2) {
                    if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                        (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                        (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                        (field[2][0] == 'X' && field[0][2] == 'O') ||//CROSS lEFT MIDDLE

                        (field[0][0] == 'X' && field[2][2] == 'O'))//CROSS  RIGHT MIDDLE
                    {
                        flag = false;

                        computer = true;

                        break;

                    }
                }
                /// 
                /// High Line
                /// 
                else if (row == 1) {
                    if (column == colums) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O') ||//CROSS  UNDER LEFT

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O'))//CROSS  UNDER RIGHT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }


                    }

                }

                /// 
                /// Left line
                //

                else if (column == 1) {

                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O'))//ROW -
                        {
                            flag = false;

                            computer = true;

                            break;
                        }
                    }

                    else if (row == 2) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -
                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+
                            (field[(row - 1) + 1][(column - 1) + 1] == 'O' && field[(row - 1) + 2][(column - 1) + 2] == 'O') ||//CROSS  UNDER RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O'))//ROW MIDDLE
                        {
                            flag = false;

                            computer = true;

                            break;

                        }
                    }

                    else if (row == rows - 1) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O') ||//CROSS HIGH RIGHT
                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O'))//ROW MIDDLE
                        {
                            flag = false;

                            computer = true;

                            break;
                        }
                    }
                    else if ((row == rows && column == 1)) {

                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {

                            flag = false;

                            computer = true;;

                            break;

                        }

                    }
                }

                /// 
                /// lower line
                //

                else if (row == rows) {
                    if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            computer = true;

                            break;
                        }

                    }
                    else if (column == 2) {
                        if ((field[(row - 1)][(column - 1) + 1] == 'O' && field[(row - 1)][(column - 1) + 2] == 'O') ||//COLUMN+

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) + 1] == 'O' && field[(row - 1) - 2][(column - 1) + 2] == 'O'))//CROSS HIGH RIGHT

                        {
                            flag = false;

                            computer = true;

                            break;
                        }

                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) + 1] == 'O') ||//COLUMN MIDDLE

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {
                            flag = false;

                            computer = true;;

                            break;
                        }
                    }
                    else if (column == colums) {
                        if ((field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                }

                /// 
                /// Right line
                //


                else if (column == colums) {
                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O') ||//CROSS HIGH lEFT

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }

                    }
                    else if (row == (rows - 1)) {
                        if (
                            (field[(row - 1) - 1][(column - 1)] == 'O' && field[(row - 1) - 2][(column - 1)] == 'O') ||//ROW -

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) - 1][(column - 1) - 1] == 'O' && field[(row - 1) - 2][(column - 1) - 2] == 'O'))//CROSS HIGH lEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }

                    }
                    else if (row == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) + 2][(column - 1)] == 'O') ||//ROW +

                            (field[(row - 1) + 1][(column - 1)] == 'O' && field[(row - 1) - 1][(column - 1)] == 'O') ||//ROW MIDDLE

                            (field[(row - 1)][(column - 1) - 1] == 'O' && field[(row - 1)][(column - 1) - 2] == 'O') ||//COLUMN-

                            (field[(row - 1) + 1][(column - 1) - 1] == 'O' && field[(row - 1) + 2][(column - 1) - 2] == 'O'))//CROSS  UNDER LEFT

                        {

                            flag = false;

                            computer = true;

                            break;

                        }
                    }
                }

                break;
            }
        }
        else {
            cout << "\n Does not exist \n";
        }
        cout << "\n Try pls another ;) \n" << endl;

    }
}


bool ContinueGame() {
    bool flag = true;
    while (true) {
        string answer;
        cout << "Do you want to continue playing? (Yes/No)" << endl << "Enter answear: "; //<< answer;
        cin >> answer;
        if (answer == "Yes") {
            break;
        }
        else if (answer == "No") {
            flag = false;
            break;
        }
        else {
            cout << "Wrond answear!";
        }
    }
    return flag;
}


int main()
{
    int rows;
    int colums;
    int level;

    boolean gamer = false;
    boolean computer = false;
    boolean vvod = true;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter colums: ";
    cin >> colums;

    char** field = CreateField(rows, colums);

    while (true) {

        FillField(field, rows, colums);

        gamer = false;

        computer = false;

        while (true) {

            while (vvod) {
                cout << "Enter number of difficult 1 or 2 : ";
                cin >> level;
                if (level == 1 || level == 2) {
                    vvod = false;
                    break;
                }
                cout << "You enter wrong number, pls enter another";
            }
           
            OutputField(field, rows, colums);
            InfillGamerField(field, rows, colums, gamer);
            if (gamer) {
                cout << " You winner \n Be happy!!!" << endl;
                break;
            }
            if (level == 1) {
                InFillComputerLevel1Field(field, rows, colums, computer);
                if (computer) {
                    cout << "you lose" << endl;
                    OutputField(field, rows, colums);
                    break;
                }
            }
            if (level == 2) {
                InFillComputerLevel2Field(field, rows, colums, computer);
                if (computer) {
                    cout << "you lose" << endl;
                    OutputField(field, rows, colums);
                    break;
                }
            }
            
        }
        if (!ContinueGame()) {
            break;
        }
    }
    DeleteField(field, rows, colums);
    return 0;

}


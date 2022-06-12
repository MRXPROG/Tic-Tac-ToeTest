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

void WinCheck(int& colums, int& rows, char** field, boolean& gamer, int who) {
    int row;
    int column; 
    int rowtest;
    int columntest;
    srand(time(NULL));
    boolean flag = true;
    boolean flagtest = true;
    char WhoElement;

    if (who == 1) {
        WhoElement = 'X';
    }
    else {
        WhoElement = 'O';
    }
    while (flag) {
        if (who == 1) {
            cout << "Please enter row, after it - column : ";
            cin >> row >> column;
        }
        else if (who == 2) {
            row = (rand() % rows) + 1;
            column = (rand() % colums) + 1;
        }
        else if (who == 3) {
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
                            if (field[1][columntest - 1] == 'X' || field[0][(columntest - 1) - 1] == 'X' || field[1][(columntest - 1) - 1] == 'X') {
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
                            if (field[(rowtest - 1) - 1][0] == 'X' || field[(rowtest - 1) - 1][1] == 'X' || field[rowtest - 1][1] == 'X') {
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
                            if (field[(rowtest - 1) - 1][(columntest - 1) - 1] == 'X' || field[(rowtest - 1) - 1][(columntest - 1) + 1] == 'X'
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
        }

        if (row <= rows && column <= colums) {
            if (field[row - 1][column - 1] == '_') {

                field[row - 1][column - 1] = WhoElement;

                if ((row != rows)
                    && (column != colums)
                    && (row != 1)
                    && (column != 1)
                    && (row != rows)
                    && (column != colums)) {
                    if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +

                        (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -

                        (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-

                        (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE

                        (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement) ||//CROSS HIGH lEFT

                        (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement) ||//CROSS  UNDER LEFT

                        (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement) ||//CROSS HIGH RIGHT

                        (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement) ||//CROSS  UNDER RIGHT

                        (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 1][(column - 1) + 1] == WhoElement) ||//CROSS lEFT MIDDLE

                        (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 1][(column - 1) + 1] == WhoElement))//CROSS  RIGHT MIDDLE

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
                    if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +

                        (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+

                        (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement))//CROSS  UNDER RIGHT
                    {

                        flag = false;

                        gamer = true;

                        break;
                    }
                }
                /// 2
                
                else if (row == 2 && column == 2) {
                    if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +

                        (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE

                        (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+

                        (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE

                        (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement) ||//CROSS  UNDER RIGHT

                        (field[2][0] == WhoElement && field[0][2] == WhoElement) ||//CROSS lEFT MIDDLE

                        (field[0][0] == WhoElement && field[2][2] == WhoElement))//CROSS  RIGHT MIDDLE
                    {
                        flag = false;
                        gamer = true;
                        break;

                    }
                }
                /// High Line
                /// 
                else if (row == 1) {
                    if (column == colums) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement))//CROSS  UNDER LEFT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (column >= 3 && column < (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement) ||//CROSS  UNDER LEFT
                            (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement))//CROSS  UNDER RIGHT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (column == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement))//CROSS  UNDER RIGHT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement))//CROSS  UNDER LEFT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                }
                 /// Left line
                else if (column == 1) {
                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement) ||//CROSS  UNDER RIGHT
                            (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement) ||//CROSS HIGH RIGHT
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement))//ROW -
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == 2) {
                        if (
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1) + 1][(column - 1) + 1] == WhoElement && field[(row - 1) + 2][(column - 1) + 2] == WhoElement) ||//CROSS  UNDER RIGHT
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement))//ROW MIDDLE
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == rows - 1) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement) ||//CROSS HIGH RIGHT
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement))//ROW MIDDLE
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == rows) {
                        if ((field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement))//CROSS HIGH RIGHT
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
                        if ((field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement) ||//CROSS HIGH lEFT
                            (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement))//CROSS HIGH RIGHT

                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (column == 2) {
                        if ((field[(row - 1)][(column - 1) + 1] == WhoElement && field[(row - 1)][(column - 1) + 2] == WhoElement) ||//COLUMN+
                            (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) - 1][(column - 1) + 1] == WhoElement && field[(row - 1) - 2][(column - 1) + 2] == WhoElement))//CROSS HIGH RIGHT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (column == (colums - 1)) {
                        if ((field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) + 1] == WhoElement) ||//COLUMN MIDDLE
                            (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement))//CROSS HIGH lEFT

                        {
                            flag = false;
                            gamer = true;;
                            break;
                        }
                    }
                    else if (column == colums) {
                        if ((field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement))//CROSS HIGH lEFT
                        {

                            flag = false;
                            gamer = true;
                            break;

                        }
                    }
                }
                /// Right line
                
                else if (column == colums) {
                    if (row >= 3 && row < (rows - 1)) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement) ||//CROSS HIGH lEFT
                            (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement))//CROSS  UNDER LEFT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == (rows - 1)) {
                        if ((field[(row - 1) - 1][(column - 1)] == WhoElement && field[(row - 1) - 2][(column - 1)] == WhoElement) ||//ROW -
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) - 1][(column - 1) - 1] == WhoElement && field[(row - 1) - 2][(column - 1) - 2] == WhoElement))//CROSS HIGH lEFT
                        {
                            flag = false;
                            gamer = true;
                            break;
                        }
                    }
                    else if (row == 2) {
                        if ((field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) + 2][(column - 1)] == WhoElement) ||//ROW +
                            (field[(row - 1) + 1][(column - 1)] == WhoElement && field[(row - 1) - 1][(column - 1)] == WhoElement) ||//ROW MIDDLE
                            (field[(row - 1)][(column - 1) - 1] == WhoElement && field[(row - 1)][(column - 1) - 2] == WhoElement) ||//COLUMN-
                            (field[(row - 1) + 1][(column - 1) - 1] == WhoElement && field[(row - 1) + 2][(column - 1) - 2] == WhoElement))//CROSS  UNDER LEFT
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
                if (who == 1) {
                    cout << "\n this element is filled \n";
                }
            }
        }
        else {
            if (who == 1) {
                cout << "\n Does not exist \n";
            }
        }
        if (who == 1) {
            cout << "\n Try pls another ;) \n" << endl;
        }
    }
}

bool ContinueGame() {
    boolean flag;
    while (true) {
        flag = true;
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

int Vvod(int& level, boolean& vvod) {
    
    while (vvod) {
        cout << "Enter number of difficult 1 or 2 : ";
        cin >> level;
        if (level == 1 || level == 2) {
            vvod = false;
            break;
        }
        cout << "You enter wrong number, pls enter another";
    }
    return level;
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

        gamer = false;
        computer = false;
        FillField(field, rows, colums);
        while (true) {

            Vvod(level, vvod);
           
            OutputField(field, rows, colums);
            WinCheck(colums, rows, field, gamer, 1);
            if (gamer) {
                cout << " You winner \n Be happy!!!" << endl;
                vvod = true;
                OutputField(field, rows, colums);
                break;
            }
            if (level == 1) {
                WinCheck(colums, rows, field, computer,2);
                if (computer) {
                    cout << "you lose" << endl;
                    vvod = true;
                    OutputField(field, rows, colums);
                    break;
                }
            }
            if (level == 2) {
                WinCheck(colums, rows, field, computer, 3);
                if (computer) {
                    cout << "you lose" << endl;
                    vvod = true;
                    OutputField(field, rows, colums);
                    break;
                }
            }
            
        }
        if (!ContinueGame()) {
            FillField(field, rows, colums);
            break;
        }

    }
    DeleteField(field, rows, colums);
    return 0;
}


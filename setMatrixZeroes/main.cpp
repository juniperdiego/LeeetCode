#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

#if 0
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
#endif
class Solution {
    public:
#if 0
        void setZeroes(vector<vector<int> > &matrix)
        {
            size_t row = matrix.size();
            if(row == 0)
                return;
            size_t col = matrix[0].size();

            vector<bool> rowHasZero(row, false); 
            vector<bool> colHasZero(col, false); 

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        rowHasZero[i] = true;
                        colHasZero[j] = true;
                    }
                }
            }

            for(int i = 0; i < row; i++)
            {
                if(rowHasZero[i])
                {
                    for(int j = 0; j < col; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < col; i++)
            {
                if(colHasZero[i])
                {
                    for(int j = 0; j < row; j++)
                    {
                        matrix[j][i] = 0;
                    }
                }
            }
        }
#endif
        void setZeroes(vector<vector<int> > &matrix)
        {
            size_t row = matrix.size();
            if(row == 0)
                return;
            size_t col = matrix[0].size();

            bool rowZeroHasZero = false;
            bool colZeroHasZero = false;
            
            for(int i = 0; i < col; i++)
            {
                if(matrix[0][i] == 0)
                {
                    rowZeroHasZero = true;
                    break;
                }
            }
            for(int i = 0; i < row; i++)
            {
                if(matrix[i][0] == 0)
                {
                    colZeroHasZero = true;
                    break;
                }
            }

            //cout << rowZeroHasZero << endl;
            //cout << colZeroHasZero << endl;

            for(int i = 1; i < row; i++)
            {
                for(int j = 1; j < col; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for(int i = 1; i < row; i++)
            {
                if(matrix[i][0] == 0)
                {
                    for(int j = 0; j < col; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int i = 1; i < col; i++)
            {
                if(matrix[0][i] == 0)
                {
                    for(int j = 0; j < row; j++)
                    {
                        matrix[j][i] = 0;
                    }
                }
            }

            //handle the first row & first col
            if(rowZeroHasZero) 
            {
                for(int j = 0; j < col; j++)
                {
                    matrix[0][j] = 0;
                }

            }
            if(colZeroHasZero) 
            {
                for(int i = 0; i < row; i++)
                {
                    matrix[i][0] = 0;
                }

            }
        }
};


int main()
{
#if 1
    vector<int> row(3, 1);
    vector< vector<int> > in(3, row);
    in[0][0] = 0;
    Solution sl;
    for(int i = 0; i < in.size(); i++)
        printVector(in[i]);
    cout << endl;
    sl.setZeroes(in);
    for(int i = 0; i < in.size(); i++)
        printVector(in[i]);
#endif
    return 0;
}

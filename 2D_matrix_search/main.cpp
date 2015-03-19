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

class Solution 
{
    public: 
#if 0
        bool searchMatrix(vector<vector<int> > &matrix, int target) 
        {  
            int rowNum =  matrix.size();
            int colNum =  matrix[0].size();
            
            int rowLow = 0; 
            int rowHigh = rowNum - 1;

            while(rowLow < rowHigh)
            {
                int mid = (rowLow + rowHigh + 1)/2;
                if(matrix[mid][0] ==  target)
                    return true;
                if(matrix[mid][0] < target)
                    rowLow = mid ;
                else
                    rowHigh = mid - 1 ;

            }
            //cout << "rowLow = " << rowLow <<endl;

            int colLow = 0; 
            int colHigh = colNum - 1;
            while(colLow <= colHigh)
            {
                int mid = (colLow + colHigh)/2;
                if(matrix[rowLow][mid] == target)
                    return true;
                if(target > matrix[rowLow][mid] )
                    colLow = mid + 1;
                else
                    colHigh = mid - 1;

            }
            return false;


        }
#endif

        bool searchMatrix(vector<vector<int> > &matrix, int target) 
        {
            
            int rowNum =  matrix.size();
            int colNum =  matrix[0].size();
            
            int low = 0;
            int high = rowNum * colNum - 1;
            int mid = 0;
            int row = 0, col = 0;

            while(low <= high)
            {
                mid = (low + high) /2;
                
                row = mid/colNum;
                col = mid%colNum;

                if(matrix[row][col] == target)
                    return true;
                if(matrix[row][col] > target)
                    high = mid -1;
                else
                    low = mid +1;
            }
            return false;

        }
};


int main()
{
    vector<vector<int> > matrix;
     vector<int> a;

     a.push_back(1);
     a.push_back(3);
     a.push_back(5);
     a.push_back(7);
     matrix.push_back(a);

     a.clear();
     a.push_back(10);
     a.push_back(11);
     a.push_back(16);
     a.push_back(20);
     matrix.push_back(a);

     a.clear();
     a.push_back(23);
     a.push_back(30);
     a.push_back(34);
     a.push_back(50);
     matrix.push_back(a);
    Solution sl;
    
    cout <<"3\t"<< sl.searchMatrix(matrix, 3)<< endl; 
    cout << "==============" <<endl;
    cout <<"10\t"<< sl.searchMatrix(matrix, 10)<< endl; 
    cout << "==============" <<endl;
    cout <<"11\t" << sl.searchMatrix(matrix, 11)<< endl; 
    cout << "==============" <<endl;
    cout <<"16\t" << sl.searchMatrix(matrix, 16)<< endl; 
    cout << "==============" <<endl;
    cout <<"17\t" << sl.searchMatrix(matrix, 17)<< endl; 
    cout << "==============" <<endl;
    cout <<"23\t" << sl.searchMatrix(matrix, 23)<< endl; 
    cout << "==============" <<endl;
    cout <<"30\t" << sl.searchMatrix(matrix, 30)<< endl; 
    cout << "==============" <<endl;
    cout <<"34\t" << sl.searchMatrix(matrix, 34)<< endl; 
    cout << "==============" <<endl;

    matrix.clear();
     a.clear();
     a.push_back(1);
     a.push_back(3);
     matrix.push_back(a);
    cout << sl.searchMatrix(matrix, 3); 
    cout << endl;
    return 0;
}

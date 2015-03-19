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


void printVector(vector<char> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

class Solution {
    public:
        void rotateFromDiagonal (vector<vector<int> > &matrix)
        {
            size_t n = matrix.size();
            int tmp;
            for(int i = 0; i < n; i ++)
                for(int j = 0; j <  n-i; j ++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[n-j-1][n-i-1];
                    matrix[n-j-1][n-i-1] = tmp;
                }
        }

        void rotateFromHorizon(vector<vector<int> > &matrix)
        {
            size_t n = matrix.size();
            int tmp;
            for(int i = 0; i < n/2; i ++)
                for(int j = 0; j < n; j ++)
                {
                    tmp = matrix[i][j];
                    matrix[i][j] = matrix[n-1-i][j];
                    matrix[n-1-i][j] = tmp;
                }
        }

        void rotate(vector<vector<int> > &matrix)
        {
            rotateFromDiagonal(matrix);
            rotateFromHorizon(matrix);
        }
#if 0
        void rotate(vector<vector<int> > &matrix)
        {
            size_t n = matrix.size();
            vector<vector<int> > re; 
            vector<int> b;
            b.resize(n);

            for(int i = 0; i < n; i ++)
                re.push_back(b);


            for(int i = 0; i < n; i ++)
                for(int j = 0; j < n; j ++)
                {
                  re[i][j] = matrix[n-j-1][i]; 
                }

            for(int i = 0; i < n; i ++)
                for(int j = 0; j < n; j ++)
                  matrix[i][j] = re[i][j]; 
        }
#endif
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    matrix.push_back(a);

    a.clear();
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    matrix.push_back(a);

    a.clear();
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    matrix.push_back(a);

    for(int i = 0; i < matrix.size(); i++)
        printVector(matrix[i]);

    Solution sl;
    sl.rotate(matrix);

    cout << endl;

    for(int i = 0; i < matrix.size(); i++)
        printVector(matrix[i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
#if 0
    // form top to down
    int minimumTotal(vector<vector<int> > &triangle) {
        
        size_t rowNum = triangle.size();
        if(rowNum == 0)
            return 0;

        vector<vector<int> >f(rowNum);

        for(size_t i = 0 ; i< rowNum; i++)
        {
            f[i].resize(i+1, 0);
        }

        for(size_t i = 0 ; i< rowNum; i++)
        {
            printVector(triangle[i]);
        }

        
        f[0][0] = triangle[0][0];
        for(size_t i = 1 ; i< rowNum; i++)
        {
            for(size_t j = 0; j <= i; j++)
            {
                int a = INT_MAX;
                if(i-1 >= 0 && j-1 >= 0 && j <= i)
                    a = f[i-1][j-1];
                int b = INT_MAX;
                if(i-1 >= 0 && j >= 0 && j <= i-1)
                    b = f[i-1][j];
                f[i][j] = min(a, b) + triangle[i][j];
            }
        }

        int res = INT_MAX; 
        for(size_t i = 0 ; i< rowNum; i++)
        {
            printVector(f[i]);
            res = min(res, f[rowNum-1][i]);
        }
        
        return res;
    }
#endif
    int minimumTotal(vector<vector<int> > &triangle) {
        
        size_t rowNum = triangle.size();
        if(rowNum == 0)
            return 0;

        vector<vector<int> >f(rowNum);

        for(size_t i = 0 ; i< rowNum; i++)
        {
            f[i].resize(i+1, 0);
        }

        for(size_t i = 0 ; i< rowNum; i++)
        {
            f[rowNum-1][i] = triangle[rowNum-1][i];
        }
        
        for(size_t i = rowNum-2 ; i >= 0; i--)
        {
            for(size_t j = 0; j <= i; j++)
            {
#if 0
                cout << "-==========&&&&&&&&&&&&" << endl;
                cout << "i = \t" << i << endl;
                cout << "j = \t" << j << endl;
#endif
                int a = f[i+1][j];
                int b = f[i+1][j+1];
                f[i][j] = min(a, b) + triangle[i][j];
            }
        }

        return f[0][0];
    }
};


int main()
{
    vector<vector<int> > triangle;
    vector<int> a;

    a.push_back(2);
    triangle.push_back(a);
    
    a.clear();
    a.push_back(3);
    a.push_back(4);
    triangle.push_back(a);

    a.clear();
    a.push_back(6);
    a.push_back(5);
    a.push_back(7);
    triangle.push_back(a);

    a.clear();
    a.push_back(4);
    a.push_back(1);
    a.push_back(8);
    a.push_back(3);
    triangle.push_back(a);

    Solution sl;
    cout << sl.minimumTotal(triangle) << endl;;
    cout <<endl<< "==============" <<endl;

    cout << endl;
    return 0;
}

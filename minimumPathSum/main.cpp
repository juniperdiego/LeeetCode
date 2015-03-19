#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>

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
        int minPathSum(vector<vector<int> > &grid) 
        {
            int m = grid.size();
            int n = grid[0].size();

            vector<int> row(n + 1, INT_MAX);
            vector<vector<int> > f(m + 1, row);

            #if 0
            for(int i = 0; i < m; i ++)
            {
                for(int j = 0; j < n; j ++)
                {
                    cout << grid[i][j] << "\t";
                }
                cout << endl;
            }
            cout << endl;
            #endif

            f[1][1] = grid[0][0];
            for(int i = 1; i <= m; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    if(i == 1 && j == 1)
                        continue;
                    f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i-1][j-1];
                }
            }

            #if 0
            for(int i = 1; i <= m; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    cout << f[i][j] << "\t";
                }
                cout << endl;
            }
            #endif

            return f[m][n];

        }
};

int main()
{
    vector<int>  row;
    vector<vector<int> > in;

    row.push_back(1);
    row.push_back(2);
    in.push_back(row);

    row.clear();
    row.push_back(1);
    row.push_back(1);
    in.push_back(row);
    
    Solution sl;
    cout << sl.minPathSum(in) << endl;
}

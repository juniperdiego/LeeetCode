#include <stdio.h>
#include <stdlib.h>
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
#if 0
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            vector<int> row(n + 1, 0);
            vector<vector<int> > f(m + 1, row);

            if(obstacleGrid[0][0] == 1)
                return 0;
            f[1][1] = 1;

            for(int i = 1; i <= m; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    if(i == 1 && j == 1)
                        continue;
                    if(obstacleGrid[i-1][j-1] == 1)
                        f[i][j] = 0;
                    else
                        f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }

            return f[m][n];
        }
#else
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            if(obstacleGrid[0][0] == 1)
                return 0;
            vector<int> f(n + 1, 0);

            f[1] = 1;

            for(int i = 1; i <= m; i ++)
            {
                for(int j = 1; j <= n; j ++)
                {
                    if(i == 1 && j == 1)
                        continue;
                    f[j] = f[j] + f[j-1];
                }
            }

            return f[n];
        }
#endif
};

int main()
{
    Solution sl;
    cout <<sl.uniquePaths(1, 1) << endl;
    cout <<sl.uniquePaths(1, 2) << endl;
    cout <<sl.uniquePaths(2, 2) << endl;
    cout <<sl.uniquePaths(2, 3) << endl;
    cout <<sl.uniquePaths(3, 7) << endl;
}

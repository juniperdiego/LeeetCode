#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

#if 0
For example,
    Given the following matrix:

    [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
    ]
    You should return [1,2,3,6,9,8,7,4,5].
#endif

class Solution {
    enum direct{RIGHT = 0, DOWN, LEFT, UP};
    vector<int> m_res;
    public:
#if 1
        void dfs(int i, int j, enum direct d, vector<vector<int> > &matrix) 
        {
            if(matrix[i][j] != INT_MIN)// this juge can be deleted
            {
                //cout << i <<",\t" << j << endl;
                m_res.push_back(matrix[i][j]);
                matrix[i][j] = INT_MIN;

                if(d == RIGHT)
                {
                    if(matrix[i][j+1] != INT_MIN)
                        dfs(1, j+1, RIGHT, matrix);
                    else if(matrix[i+1][j] != INT_MIN)
                        dfs(i+1, j, DOWN, matrix);
                }
                else if(d == DOWN)
                {
                    if(matrix[i+1][j] != INT_MIN)
                        dfs(i+1, j, DOWN, matrix);
                    else if(matrix[i][j-1] != INT_MIN)
                        dfs(i, j-1, LEFT, matrix);
                }
                else if(d == LEFT)
                {
                    if(matrix[i][j-1] != INT_MIN)
                        dfs(i, j-1, LEFT, matrix);
                    else if(matrix[i-1][j] != INT_MIN)
                        dfs(i-1, j, UP, matrix);
                }
                else if(d == UP)
                {
                    if(matrix[i-1][j] != INT_MIN)
                        dfs(i-1, j, UP, matrix);
                    else if(matrix[i][j+1] != INT_MIN)
                        dfs(i, j+1, RIGHT, matrix);
                }
            }

                
        }
#endif
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            int row = matrix.size();
            int col = matrix[0].size();
            vector<vector<int> > newMat;
            vector<int>  intVec(col+2, INT_MIN);
            newMat.push_back(intVec);
            
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    intVec[j+1] = matrix[i][j];
                }
                newMat.push_back(intVec);
            }

            intVec.clear();
            intVec.resize(col+2, INT_MIN);
            newMat.push_back(intVec);
            
            //for(int i = 0; i < newMat.size(); i++)
            //    printVector(newMat[i]);

            dfs(1,1,RIGHT,newMat);

            return m_res;

        }
};

int main()
{
    vector<vector<int> > mat;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    mat.push_back(a);

    a.clear();
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    mat.push_back(a);

    a.clear();
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    mat.push_back(a);

    Solution sl;
    printVector(sl.spiralOrder(mat));

    return 0;
}

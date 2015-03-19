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
    vector<vector<int> > m_matrix;
    vector<vector<bool> > m_valid;
    int m_cnt;
    public:
        void dfs(int i, int j, enum direct d) 
        {
            int row = m_matrix.size();
            int col = m_matrix[0].size();

            //cout << i <<",\t" << j << endl;
            m_cnt++;
            m_matrix[i][j] = m_cnt;
            m_valid[i][j] = false;

            if(d == RIGHT)
            {
                if( j <= col-2 && m_valid[i][j+1])
                    dfs(i, j+1, RIGHT);
                else if(i <= row-2 && m_valid[i+1][j])
                    dfs(i+1, j, DOWN);
            }
            else if(d == DOWN)
            {
                if(i <= row-2 && m_valid[i+1][j])
                    dfs(i+1, j, DOWN);
                else if(j >= 1 && m_valid[i][j-1])
                    dfs(i, j-1, LEFT);
            }
            else if(d == LEFT)
            {
                if(j >= 1 && m_valid[i][j-1] )
                    dfs(i, j-1, LEFT);
                else if(i >= 1 && m_valid[i-1][j])
                    dfs(i-1, j, UP);
            }
            else if(d == UP)
            {
                if(i >= 1 && m_valid[i-1][j])
                    dfs(i-1, j, UP);
                else if(j <= col-1 && m_valid[i][j+1])
                    dfs(i, j+1, RIGHT );
            }
        }
public:
        vector<vector<int> > generateMatrix(int n)
        {
            if(n == 0)
                return m_matrix;

            // construct the matrix
            vector<int> row(n, 0);
            m_matrix.resize(n, row);
            //for(int i = 0; i < n; i++)
            //    m_matrix.push_back(row);

            vector<bool> valid(n, true);
            m_valid.resize(n, valid);
            //for(int i = 0; i < n; i++)
            //    m_valid.push_back(valid);

            m_cnt = 0;

            dfs(0, 0, RIGHT);

            return m_matrix;
        }
};

int main()
{
    vector<vector<int> > out;

    Solution sl;
    out = sl.generateMatrix(4);

    for(int i = 0; i < out.size(); i++)
        printVector(out[i]);

    return 0;
}

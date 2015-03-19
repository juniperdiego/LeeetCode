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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

class Solution {
    vector<int> x;
    vector< vector<string>  > m_res;

    bool checkTwoPoints(int i, int j, int xi, int xj)
    {
        //cout << "check i\t" << i << endl;
        //cout << "check j\t" << j << endl;
        if(xi == xj) // same column
            return false;
        if( abs(xi-xj) == abs(i-j)) // diag
            return false;
        return true;
    }

    bool check(vector<int> x, int n) // check x[n] and x[0 .. n-1]
    {
        for(int i = 0; i < n; i++)
        {
            if(!checkTwoPoints(i, n, x[i], x[n]))
                return false;
        }
        return true;
    }

    void dfs(int n)
    {
        if(n == x.size() )
        {
            printVector(x);
            
#if 1
            string tmpStr;
            vector<string> strs;
            strs.resize(x.size());
            for(int i = 0; i < x.size(); i++)
                tmpStr += '.';

            for(int i = 0; i < x.size(); i++)
            {
                strs[i] = tmpStr;
                strs[i][x[i]] = 'Q';
                cout << strs[i] << endl;
            }
            cout << endl;
            //m_res.push_back(strs);
            return;
#endif
        }

        for(int i = 0; i < x.size(); i++)
        {
            x[n] = i;

            // check if x[n] is available
            if(check(x, n))
                dfs(n+1);
        }

    }
    public:
    vector<vector<string> > solveNQueens(int n) 
    {
        x.resize(n);
        dfs(0);
        return m_res;
    }
};

int main()
{
    Solution sl;
    vector<vector<string> > out = sl.solveNQueens(6);

    return 0;
}

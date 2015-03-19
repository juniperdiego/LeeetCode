#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

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
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
    If n = 4 and k = 2, a solution is:

    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
#endif
class Solution {
    vector<vector<int> > m_res;
    vector<int>  m_array;
    public:
        void dfs(int n, int k, int dep)
        {
            if(k == m_array.size())
            {
                m_res.push_back(m_array);
                return;
            }

            if(dep > n)
                return;

            // contain the element
            m_array.push_back(dep);
            dfs(n, k, dep+ 1);
            m_array.pop_back();

            // don't contain the element
            dfs(n, k, dep+1);

        }

        vector<vector<int> > combine(int n, int k)
        {
            dfs(n, k, 1);
            return m_res;
        }
};

int main()
{
    Solution sl;
    vector<vector<int> >  out = sl.combine(4, 2);

    for(int i = 0; i < out.size(); i++)
    {
        printVector(out[i]);
    }
    return 0;
}

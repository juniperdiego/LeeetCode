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
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
    If S = [1,2,3], a solution is:

    [
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
    ]
#endif
class Solution {
    vector<vector<int> > m_res;
    vector<int>  m_array;
public:
#if 0
    void dfs(int n, int k, int start, vector<int> & in)
    {
        if(k == m_array.size())
        {
            m_res.push_back(m_array);
            return;
        }
        for(int i = start; i < n; i++)
        {
            m_array.push_back(in[i]);
            dfs(n, k, i + 1, in);
            m_array.pop_back();
        }

    }

    void combine(int n, int elementNum, vector<int> & in)
    {
        dfs(n, elementNum, 0, in);
    }
    public:
        vector<vector<int> > subsets(vector<int> &S) {

            sort(S.begin(), S.end());

            for(int i = 0; i <= S.size(); i++)
            {
                combine(S.size(), i,  S);
                m_array.clear();
            }

            return m_res;
        }
#endif
        void dfs(int dep, vector<int> &S)
        {
            if(dep == S.size())
            {
                m_res.push_back(m_array);
                return ;
            }

#if 0
            for(int i = 0; i< 2; i++)
            {
                // contain the element
                if(i == 0)
                {
                    m_array.push_back(S[dep]);
                    dfs(dep + 1, S);
                    m_array.pop_back();
                }
                // don't contain the element
                else
                    dfs(dep + 1, S);
            }
#else 
            // contain the element
            m_array.push_back(S[dep]);
            dfs(dep + 1, S);
            m_array.pop_back();

            // don't contain the element
            dfs(dep + 1, S);
#endif
        }

        vector<vector<int> > subsets(vector<int> &S) {

            sort(S.begin(), S.end());

            dfs(0, S);

            return m_res;
        }

    

};

int main()
{
    Solution sl;
    vector<int> in;
    in.push_back(3);
    in.push_back(1);
    in.push_back(2);
    vector<vector<int> >  out = sl.subsets(in);

    for(int i = 0; i < out.size(); i++)
    {
        printVector(out[i]);
    }
    return 0;
}

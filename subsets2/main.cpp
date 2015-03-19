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
    vector<bool> m_canUse;
public:
        void dfs(int dep, vector<int> &S)
        {
            m_res.push_back(m_array);

            for(int idx = dep; idx < S.size(); idx ++)
            {
                if(idx > 0 && m_canUse[idx-1] == true && S[idx] == S[idx-1])
                    continue;
                m_array.push_back(S[idx]);
                m_canUse[idx] = false;
                dfs(idx + 1, S);
                m_array.pop_back();
                m_canUse[idx] = true;
            }
        }

        vector<vector<int> > subsets(vector<int> &S) {

            sort(S.begin(), S.end());

            m_canUse.clear();
            m_canUse.resize(S.size(), true);

            dfs(0, S);

            return m_res;
        }

    

};

int main()
{
    Solution sl;
    vector<int> in;
    in.push_back(2);
    in.push_back(1);
    in.push_back(2);
    vector<vector<int> >  out = sl.subsets(in);

    for(int i = 0; i < out.size(); i++)
    {
        printVector(out[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
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

class Solution
{
    vector<vector<int> > m_result;
    public:

    void dfs(const vector<int> &candidates, int target, vector<int>& array, int start) 
    {
        if(target == 0)
        {
            m_result.push_back(array);
            return;
        }

        for(size_t i = start; i < candidates.size(); i++)
        {
            if(target < candidates[i])
                return;
            array.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], array, i);
            array.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<int> array;
        sort(candidates.begin(), candidates.end());
        vector<int>::iterator pos = unique(candidates.begin(), candidates.end());  
        candidates.erase(pos, candidates.end()); 
        dfs( candidates, target, array, 0);

        return m_result;
    }
};

int main()
{
    vector<int> cand;
    cand.push_back(2);
    cand.push_back(3);
    cand.push_back(6);
    cand.push_back(7);

    Solution sl;
    vector<vector<int> >result = sl.combinationSum (cand, 7);

    for(int i = 0; i < result.size(); i++)
    {
        printVector(result[i]);
    }

    return 0;
}

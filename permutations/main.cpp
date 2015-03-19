#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>

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

class Solution {
        vector<vector<int> > m_result;
    public:
        void swap(int & x, int & y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        void dfs(vector<int> & num, int dep )
        {
            if(dep == num.size())
            {
                m_result.push_back(num);
                return;
            }

            for(int i = dep; i < num.size(); i++)
            {
                    //if(i != dep && num[i] == num[dep])
                    //    continue;
                    swap(num[i], num[dep]);
                    dfs(num, dep + 1);
                    swap(num[i], num[dep]);
            }
        }
        
        vector<vector<int> > permute(vector<int> &num)
        {
            dfs( num, 0);

            //erase the duplicate
            sort(m_result.begin(), m_result.end());
            m_result.erase(unique(m_result.begin(), m_result.end()), m_result.end());

            return m_result;
        }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);

    Solution sl;
    vector<vector<int> >ret = sl.permute(num);

    for(int i = 0; i < ret.size(); i++)
        printVector(ret[i]);

    return 0;
}

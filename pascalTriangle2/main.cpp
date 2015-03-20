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
class Solution {
    public:
        vector<int> getRow(int rowIdx) {
            vector<int> curLine;
            vector<vector<int> >  res;
            curLine.push_back(1);
            res.push_back(curLine);
            if( rowIdx == 0)
                return curLine;

            for(int i = 1; i <= rowIdx; i++)
            {
                curLine.clear();
                for(int j = 0; j < res[i-1].size(); j++)
                {
                    if(j == 0)
                        curLine.push_back(1);
                    else
                        curLine.push_back(res[i-1][j-1] + res[i-1][j]);
                }
                curLine.push_back(1);
                res.push_back(curLine);
            }
            return res[rowIdx];
        }
};
#endif
class Solution {
    public:
        vector<int> getRow(int rowIdx) {
            vector<int> preLine;
            vector<int> curLine;

            curLine.push_back(1);
            
            if(rowIdx == 0)
                return curLine;
            
            for(int i = 1; i <= rowIdx; i++)
            {
                preLine = curLine;
                curLine.clear();
                
                for(int j = 0; j < preLine.size(); j++)
                {
                    if(j == 0)
                        curLine.push_back(1);
                    else
                        curLine.push_back(preLine[j-1] + preLine[j]);

                }
                curLine.push_back(1);
            }
            return curLine;
        }
};


int main()
{
    Solution sl;
    vector<int>  out ;

    out = sl.getRow(0);
    printVector(out);
    cout << endl;

    out = sl.getRow(1);
    printVector(out);
    cout << endl;

    out = sl.getRow(2);
    printVector(out);
    cout << endl;

    out = sl.getRow(3);
    printVector(out);
    cout << endl;


    return 0;
}

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

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> >  res;
            if(numRows == 0)
                return res;
            vector<int> curLine;
            curLine.push_back(1);
            res.push_back(curLine);

            for(int i = 1; i < numRows; i++)
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
            return res;
        }
};


int main()
{
    Solution sl;
    vector<vector<int> > out = sl.generate(1);
    for(int i = 0; i < out.size();i++)
        printVector(out[i]);
    cout << endl;

    out = sl.generate(2);
    for(int i = 0; i < out.size();i++)
        printVector(out[i]);
    cout << endl;

    out = sl.generate(3);
    for(int i = 0; i < out.size();i++)
        printVector(out[i]);
    cout << endl;

    out = sl.generate(4);
    for(int i = 0; i < out.size();i++)
        printVector(out[i]);
    cout << endl;

    out = sl.generate(5);
    for(int i = 0; i < out.size();i++)
        printVector(out[i]);
    cout << endl;


    return 0;
}

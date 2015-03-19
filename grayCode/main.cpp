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
        vector<int> grayCode(int n) 
        {
            vector<int> res ;


            res.push_back(0);

            for(int i = 0; i < n; i++)
            {
                int size = res.size();
                for(int j = size -1; j >= 0; j--)
                {
                    res.push_back(res[j] + (1 << i));
                }
            }


            return res;
        }
};

#if 0
00 - 0
01 - 1
11 - 3
10 - 2
#endif

int main()
{
    Solution sl;
    printVector(sl.grayCode(1));
    printVector(sl.grayCode(2));
    printVector(sl.grayCode(3));
    printVector(sl.grayCode(4));
    return 0;
}

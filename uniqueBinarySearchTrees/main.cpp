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
        int numTrees(int n) {

            int *num = new int[n+1];

            num[0] = 1;
            num[1] = 1;
            int tmp = 0;

            for(int i =2; i <=n; i++)
            {
                tmp = 0;
                for(int j= 0; j <i ;j++)
                    tmp += num[j]*num[i-j-1];
                num[i] = tmp;
            }

            tmp =  num[n];

            delete []num;

            return tmp;

        }
};


int main()
{


    Solution sl;
#if 1
    cout << sl.sqrt( 0) << endl;
    cout << sl.sqrt( 1) << endl;
    cout << sl.sqrt( 2) << endl;
    cout << sl.sqrt( 3) << endl;
    cout << sl.sqrt( 4) << endl;
    cout << sl.sqrt( 5) << endl;
    cout << sl.sqrt( 8) << endl;
    cout << sl.sqrt( 16) << endl;
#endif
    cout << sl.sqrt( INT_MAX) << endl;

    return 0;
}

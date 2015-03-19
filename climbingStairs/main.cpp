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
        int climbStairs(int n) {

            vector<int> f(n+1, 0);
            f[0] = 1;
            f[1] = 1;

            for(int i = 2; i <= n; i++)
            {
                f[i] = f[i-1] + f[i-2];
            }

            return f[n];
        }
};


int main()
{


    Solution sl;
    cout << sl.climbStairs(0) << endl;
    cout << sl.climbStairs(1) << endl;
    cout << sl.climbStairs(2) << endl;
    cout << sl.climbStairs(3) << endl;
    cout << sl.climbStairs(4) << endl;
    cout << sl.climbStairs(5) << endl;

    return 0;
}

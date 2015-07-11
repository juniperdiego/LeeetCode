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
        bool isPowerOfTwo(int n) {
            if (n <= 0)
                return false;
            if ((n & (n-1)) == 0)
                return true;
            else
                return false;
        }
};


int main()
{


    Solution sl;
    cout << sl.isPowerOfTwo(0) << endl;
    cout << sl.isPowerOfTwo(1) << endl;
    cout << sl.isPowerOfTwo(2) << endl;
    cout << sl.isPowerOfTwo(3) << endl;
    cout << sl.isPowerOfTwo(4) << endl;
    cout << sl.isPowerOfTwo(5) << endl;
    cout << sl.isPowerOfTwo(6) << endl;
    cout << sl.isPowerOfTwo(7) << endl;
    cout << sl.isPowerOfTwo(8) << endl;
    cout << sl.isPowerOfTwo(INT_MIN) << endl;
    cout << sl.isPowerOfTwo( INT_MAX) << endl;

    return 0;
}

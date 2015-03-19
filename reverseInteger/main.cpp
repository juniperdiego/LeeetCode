#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<char> array )
{
    for(int i = 0; i <array.size(); i++)
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
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int sign = x > 0 ? 1 : -1;
            long long y = abs(x);

            long long ret = 0;
            while(y)
            {
                int digit = y % 10;
                ret = ret * 10 + digit;
                y /= 10;
                if(ret * sign > INT_MAX)
                    return 0;
                if(ret * sign < INT_MIN)
                    return 0;
            }

            return ret * sign;
        }
};

int main()
{

    Solution sl;
    cout <<(sl.reverse(-123)) << endl;
    cout <<(sl.reverse(1534236469)) << endl;
    cout <<(sl.reverse(-2147483648)) << endl;
    long long m = -2147483648;
    m = abs(m);
    cout <<"m\t" << m <<endl;
}

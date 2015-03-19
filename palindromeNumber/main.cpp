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
#include <math.h>

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

        bool isPalindrome(int x) {
            if(x == 0)
                return true;
            if(x < 0)
                return false;
            int y = reverse(x);
            if(x == y)
                return true;
            else 
                return false;
        }

        bool isPalindrome2(int x) {
            if(x < 0)
                return false;
            if(x < 10)
                return true;

            int base = 0;

            int y = x;
            int z = 0;

            while(y)
            {
               y = y/10;
               base++;
            }

            y = x;

            cout << "base:\t" << base << endl;

            for(int i = 0; i< base/2; i++)
            {
                y = y/pow(10,base-i-1);
                z = x%10;
                x = x/10;
                cout << "i:\t" << i << endl;
                cout << "x:\t" << x << endl;
                cout << "y:\t" << y << endl;
                cout << "z:\t" << z << endl;
                if(y != z)
                    return false;
            }
            return true;
        }
};

int main()
{

    Solution sl;
//    cout << sl.isPalindrome2(121) << endl;
//    cout << sl.isPalindrome2(1001) << endl;
    //cout << sl.isPalindrome2(10) << endl;
    cout << sl.isPalindrome2(9999) << endl;
}

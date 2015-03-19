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
        double pow(double x, int n)
        {
            long long ln = n;
            return powl(x, ln);
        }
        double powl(double x, long long n)
        {
            if(n < 0)
                return 1/powl(x, -n);
            if(n == 0)
                return 1;
            if(n == 1)
                return x;
            
            if( n & 0x1 == 1)
            {
                double tmp = powl(x, n/2);
                return tmp* tmp * x;
            }
            else
            {
                double tmp = powl(x, n/2);
                return tmp* tmp ;
            }

        }
};


int main()
{


    Solution sl;
    cout << sl.pow(2, 0) << endl;
    cout << sl.pow(2, 1) << endl;
    cout << sl.pow(2, 2) << endl;
    cout << sl.pow(2, 3) << endl;
    cout << sl.pow(2, 4) << endl;
    cout << sl.pow(2, 5) << endl;
    cout << sl.pow(2, -5) << endl;
    cout << sl.pow(1, -5) << endl;
    cout << sl.pow(1, INT_MIN) << endl;
    cout << sl.pow(1, INT_MAX) << endl;

    return 0;
}

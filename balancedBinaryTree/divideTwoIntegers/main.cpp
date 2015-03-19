#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

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
    public:
        int divide(int dividend, int divisor) 
        {
            int leftShiftBits= 0;
            long long divd = dividend;
            long long divr = divisor;
            long long result = 0;
            int sign = 1;

            if( (divd < 0 && divr > 0) || (divd > 0 && divr < 0) )
                sign = -1;
# if 0
            //note abs(int) can't handle abs(long), so abs(INT_MIN) will overflow
            divd = abs(divd);
            divr = abs(divr);
# endif
            if(divd < 0)
                divd = -divd;
            if(divr < 0)
                divr = -divr;
            
            while( (divr << leftShiftBits) < divd)
            {
                leftShiftBits ++;
            }

            //leftShiftBits --; //the function can work with or without this scentence

            while(leftShiftBits >= 0)
            {
                if(divd >= (divr << leftShiftBits))
                {
                    result += 1ULL << leftShiftBits;
                    divd -= (divr << leftShiftBits);
                }
                leftShiftBits --;
            }

            if((result * sign) > INT_MAX) return INT_MAX;
            else if((result * sign) < INT_MIN) return INT_MIN;
            return result * sign;
        }
};


int main()
{

    Solution    sl;

    //cout << INT_MAX << endl;
    //cout << INT_MIN << endl;
    //cout << sl.divide(100,10) << endl; 
    //cout << sl.divide(100,3) << endl; 
    //cout << sl.divide(100,-10) << endl; 
    //cout << sl.divide(INT_MAX,1) << endl; 
    //cout << sl.divide(INT_MIN,-1) << endl; 
    //cout << sl.divide(INT_MIN,1) << endl; 


    cout << (1 << 31) << endl;
    cout << (1u << 31) << endl;
    cout << (1 << 32) << endl;
    cout << (1ull << 32) << endl;

    return 0;
}

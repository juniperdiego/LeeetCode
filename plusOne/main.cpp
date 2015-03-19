#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

class Solution 
{
    public:   
    vector<int> plusOne(vector<int> &digits)
    {
        int carry =  1;
        int tmp = 0;
        for(int i = digits.size()-1; i >=0; i--)
        {
            tmp =  digits[i] + carry;
            digits[i] =  tmp % 10;
            carry  =  tmp / 10;
        }
        if(carry != 0)
            digits.insert(digits.begin() ,carry);
        return digits;
    }
} ;


int main()
{

vector<int> a;
a.push_back(1);
a.push_back(2);
a.push_back(3);
a.push_back(4);
    Solution sl;
     printVector (sl.plusOne(a));
    cout <<endl<< "==============" <<endl;
    a.clear();
a.push_back(9);
a.push_back(9);
a.push_back(9);
a.push_back(9);
     printVector (sl.plusOne(a));

    cout << endl;
    return 0;
}

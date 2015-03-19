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
        string addBinary(string a, string b)
        {
            string c;
            int carry =  0;
            int tmp = 0;
            int size = max(a.size(), b.size());
            
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());


            for(int i = 0; i < size ; i++)
            {
                int ta = 0;
                int tb = 0;
                if(i < a.size())
                    ta = a[i] - '0';
                if(i < b.size())
                    tb = b[i] - '0';

                tmp =  ta + tb + carry;
                c.insert(c.begin(), tmp % 2 + '0');
                carry  =  tmp / 2;
            }

            if(carry != 0)
                c.insert(c.begin() ,'1');
            return c;
        }
} ;


int main()
{

    string a = "11";
    string b = "1";
    Solution sl;
    string c =  sl.addBinary(a, b);
    cout << c ;

    cout << endl;
    return 0;
}

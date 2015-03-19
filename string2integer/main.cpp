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
        int atoi(const char *str) {

            if(str == NULL)
                return 0;
            char* p = (char*)str;
            int sign = 1;

            while(*p == ' ')
                p++;
            int result = 0;

            if(*p == '-')
            {
                sign = -1;
                p++;
            }
            else if(*p == '+')
            {
                sign = 1;
                p++;
            }

            while(*p != '\0')
            {
                if(*p <'0' || *p > '9')
                    break;
                if(result > INT_MAX/10)
                {
                    if(sign == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                    
                //cout << result <<endl;  
                result = result *10 + *p - '0';
                p++;
            }

            return result*sign;
        }
};



int main()
{
    char str[] = "1234567";
    Solution sl;
    cout << sl.atoi(str) << endl;;


}

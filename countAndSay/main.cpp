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
        string count(string str)
        {
            int counter = 0;
            string result;
            char pre = str[0];
            str += ' ';

            for(size_t i = 0; i < str.size(); i++)
            {
                if(str[i] == pre)
                {
                    counter ++;
                }
                else
                {
                    result += ( counter + '0');
                    result += pre ;
                    pre = str[i];
                    counter = 1;
                }
#if 0
                //handle the last char
                if(i == str.size() -1)
                {
                    if(str[i] == pre)
                    {
                        result += ( counter + '0');
                        result += pre ;
                    }
                    else
                    {
                        result += '1';
                        result += str[i];
                    }
                }
#endif
            }

            return result;
        }
        string countAndSay(int n) 
        {
           if(n == 1)
            return "1";
            
            string str = "1";
            
            for(int i = 1; i < n; i++)
            {
                str = count(str);
            }
            return str;
        }
};


int main()
{

    Solution sl;
    cout <<sl.countAndSay(1) << endl;
    cout <<sl.countAndSay(2) << endl;
    cout <<sl.countAndSay(3) << endl;
    cout <<sl.countAndSay(4) << endl;
    cout <<sl.countAndSay(5) << endl;
}

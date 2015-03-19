#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>

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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


class Solution {
        vector<string> m_strs;
    public:
        void backtrace(string  str, int leftPaNum, int paNum)
        {
            if(leftPaNum == paNum && str.size() == 2*paNum)
            {
                m_strs.push_back(str);
                return;
            }
            if(leftPaNum == paNum)
            {
                str += ")";
                backtrace(str, leftPaNum, paNum);
            }
            else
            {
                // left num == right num
                if(leftPaNum  == (str.size()-leftPaNum) )
                {
                    str += "(";
                    backtrace(str, leftPaNum + 1, paNum);
                }
                else// left num > right num
                {
                    str += "(";
                    backtrace(str, leftPaNum + 1, paNum);
                    str.erase(str.end() - 1);
                    str += ")";
                    backtrace(str, leftPaNum, paNum);
                }
            }
        }

        vector<string> generateParenthesis(int n)
        {
            m_strs.clear();
            string str;
            backtrace(str, 0, n);
            return m_strs;
        }
};





int main()
{

   Solution sl;
   vector<string> result;
   result = sl.generateParenthesis(1);
   printVector(result);
   result = sl.generateParenthesis(2);
   printVector(result);
   result = sl.generateParenthesis(3);
   printVector(result);
   result = sl.generateParenthesis(4);
   printVector(result);
}

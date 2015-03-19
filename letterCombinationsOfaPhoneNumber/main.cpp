#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

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

void printVector(vector<string> array )
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
            map<char, string> m_maps;
            string m_digits;
    public:
       void backtrace(string & inStr, vector<string> & result)
//       void backtrace(string  inStr, vector<string> & result)
        {
            if(inStr.size() == m_digits.size())
            {
                result.push_back(inStr);
                return;
            }
            size_t inSize = inStr.size(); 
            string charMap = m_maps[m_digits[inSize]];

            for(size_t i = 0; i < charMap.size(); i++)
            {
                inStr += charMap[i];
                backtrace(inStr, result);
                inStr.erase(inStr.end() - 1); 
            }
        }

        vector<string> letterCombinations(string digits) {
            vector<string> result;
            string inStr;
            
            m_maps['2'] = "abc";
            m_maps['3'] = "def";
            m_maps['4'] = "ghi";
            m_maps['5'] = "jkl";
            m_maps['6'] = "mno";
            m_maps['7'] = "pqrs";
            m_maps['8'] = "tuv";
            m_maps['9'] = "wxyz";
            m_maps['0'] = " ";

            m_digits = digits;

            backtrace(inStr, result);

            return result;
        }
};


int main()
{
    Solution  sl;
    vector<string> result = sl.letterCombinations("243");
    printVector( result);
}

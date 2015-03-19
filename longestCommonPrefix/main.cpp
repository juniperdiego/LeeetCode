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
    public:  
        string longestCommonPrefix(vector<string> &strs) {  
            if(strs.size() == 0)
                return "";  

            size_t size = strs[0].size();  
            size_t idx = 0;

            for(size_t i = 0; i < size; i++ )
            {
                for(size_t j = 1; j < strs.size(); j++ )
                {
                    if(strs[j][i] != strs[0][i])
                    {
                        return strs[0].substr(0,idx);
                    }
                }
                idx ++;
            }
            return strs[0].substr(0,idx);

        }  
};  


int main()
{
    Solution  sl;
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("abc");
    strs.push_back("abc");
    string result = sl.longestCommonPrefix(strs);
    cout <<  result << endl;;
}

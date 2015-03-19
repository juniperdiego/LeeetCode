#include <stdio.h>
#include <stdlib.h>
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
        vector<string> anagrams(vector<string> &strs)
        {
            size_t n = strs.size();
            map<string, int> hash;
            vector<string> res;

            string str;
            
            for(int i = 0; i < n; i++)
            {
                str = strs[i];
                sort(str.begin(), str.end());
                if(hash.count(str) == 0)
                    hash[str] = 1;
                else
                    hash[str] ++;
            }

            for(int i = 0; i < n; i++)
            {
                str = strs[i];
                sort(str.begin(), str.end());
                if(hash[str] > 1)
                    res.push_back(strs[i]);
            }
            
            return res;

        }
};

int main()
{

    vector<string> in;
    vector<string> out;
    in.push_back("abc");
    in.push_back("bcd");
    in.push_back("def");
    in.push_back("cba");
    in.push_back("abc");

    Solution sl;
    out = sl.anagrams(in);
    printVector(out);

    return 0;
}

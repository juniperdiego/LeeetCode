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

class Solution 
{
    public:   
        int lengthOfLongestSubstring(string s) 
        {
            int hash[256]; // save the index of s[i]
            int  start = -1;
            int len = 0;

            memset(hash, -1, sizeof(hash));

            for(int i = 0; i< s.size(); i++/**/)
            {
                // update the start if the start is in the front of the old hash[s[i]]
                if(start < hash[s[i]])
                    start = hash[s[i]];
                len = max(i - start, len);
                hash[s[i]] = i;
            }

            return len;
        }
};

int main()
{
    string str1 = "abcabcabc";
    string str2 = "bbbbb";
    string str3 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";

   Solution sl;
   cout <<"res = " << sl. lengthOfLongestSubstring(str1) << endl;
   //cout <<"res = " << sl. lengthOfLongestSubstring(str2) << endl;
   cout <<"res = " << sl. lengthOfLongestSubstring(str3) << endl;
}

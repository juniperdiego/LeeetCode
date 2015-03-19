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

#if 0
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
#endif
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if(s == NULL || p == NULL)
                return false;
            if(*s == '\0')
                return *p == '\0';
            if(*p == '\0')
                return *s == '\0';

            cout << string(s).size()<< "\ts:\t" <<s <<endl;
            cout << string(p).size()<< "\tp:\t" <<p <<endl;
            cout << endl;
            
            if(*(p+1) == '*')
            {
                while(*s != '\0' && (*s == *p || *p == '.'))
                {
                    if(isMatch(s, p+2))
                        return true;
                    s++;
                }
                return isMatch(s, p+2);
            }
            else
            {
                if ((*s != '\0') && ((*s == *p) || ('.' == *p))) {
                    return isMatch(s + 1, p + 1);
                }

                return false;
            }
        }
};



int main()
{
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    string str = "PAYPALISHIRING";
    Solution sl;

    //cout << sl.isMatch("aa","a") <<endl; 
    //cout << sl.isMatch("aa","aa") <<endl;
    //cout << sl.isMatch("aaa","aa") <<endl;
    //cout << sl.isMatch("aa", "a*") <<endl;
    //cout << sl.isMatch("aa", ".*") <<endl;
    //cout << sl.isMatch("ab", ".*") <<endl;
    cout << sl.isMatch("cccccccaab", "c*a*b") <<endl;

}

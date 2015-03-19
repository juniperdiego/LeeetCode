#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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


#if 0
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
#endif

#if 0
class Solution {
    int m_cnt;
    public:
        void numDecode(int dep, string s)
        {
            if(dep == s.size())
            {
                m_cnt ++;
                return;
            }

            if( s[dep] >= '1' && s[dep] <= '9') 
                numDecode(dep+1, s);
            else if( dep >= 1 && s[dep] == '0' &&
                    (s[dep-1] == '1' || s[dep-1] == 2) )
                numDecode(dep+1, s);

            if((dep+1) < s.size())
            {
                if( s[dep] == '1' || (s[dep] == '2' &&
                s[dep+1] >= '0' && s[dep+1] <= '6') )
                    numDecode(dep+2, s);
            }
        }
        int numDecodings(string s) {
            m_cnt = 0;
            numDecode(0, s);
            return m_cnt;
        }
};
#else
class Solution {
    public:
        int numDecodings(string s) {
            
            if(s.size() == 0)
                return 0;

            int f[s.size()];
            if(s[0] >= '1' && s[0] <= '9')
                f[0] = 1;
            else
                f[0] = 0;

            if(s.size() == 1)
                return f[0];

            if(s[1] == '0')
            {
                if(s[0] == '1' || s[0] == '2')
                    f[1] = 1;
                else
                    return 0;
            }
            else
            {
                if( s[0] == '1' || ( s[0] == '2' &&
                        s[1] >= '1' && s[1] <= '6' ))
                    f[1] = 2;
                else// default: if(s[i] >= '1' && s[i] <= '9' )
                    f[1] = f[0];
            }


            for(int i = 2; i < s.size(); i ++)
            {
                if(s[i] == '0')
                {
                    if(s[i-1] == '1' || s[i-1] == '2')
                        f[i] = f[i-2];
                    else
                        return 0;
                }
                else
                {
                    if( s[i-1] == '1' || (s[i-1] == '2' &&
                            s[i] >= '1' && s[i] <= '6') )
                        f[i] = f[i-1] + f[i-2];
                    else// default: if(s[i] >= '1' && s[i] <= '9' )
                        f[i] = f[i-1];
                }
            }

            return f[s.size() -1];
        }
};
#endif


int main()
{
    Solution sl;
    //cout << sl.numDecodings("12")<<endl;;
    //cout << sl.numDecodings("123")<<endl;;
    //cout << sl.numDecodings("1222")<<endl;;
    //cout << sl.numDecodings("100")<<endl;;
    //cout << sl.numDecodings("301")<<endl;;
    //cout << sl.numDecodings("17")<<endl;;
    cout << sl.numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253")<<endl;;

    return 0;
}

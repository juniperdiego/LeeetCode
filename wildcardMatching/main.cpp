#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
    public:
#if 0
        bool isMatch(const char *s, const char *p)
        {
            //cout << "==========" << endl;
            //cout << "s\t"  <<s <<endl;
            //cout << "p\t" <<p <<endl;
            if(*s == '\0')
            {
                if(*p == '\0')
                    return true;
                while(*p != '\0')
                {
                    if(*p != '*')
                        return false;
                    p++;
                }

                // *p == '\0' now
                return true;
            }

            if(*s == *p || *p == '.')
                return isMatch(s+1, p+1);
            else
            {
                if(*p == '*')
                {
                    while(*s != '\0')
                    {

                        if(isMatch(s, p))
                            return true;
                        else
                            s++;
                    }

                    // *s == '\0' now
                    return isMatch(s, p);
                }
                else
                    return false;
            }
        }
#endif
        bool isMatch(const char *s, const char *p) {

            const char *last_s = NULL; 
            const char *last_p = NULL;
            while( *s != '\0' ){
                cout << "s\t" << s << endl;
                cout << "p\t" << p << endl;
                if (*p=='*'){
                    //skip the "*", and mark a flag
                    p++;
                    //edge case
                    if (*p=='\0') return true;
                    //use last_s and last_p to store where the "*" match starts.
                    last_s = s;
                    last_p = p;
                }else if (*p=='?' || *s == *p){
                    s++; p++;
                }else if (last_s != NULL){ // check "last_s" to know whether meet "*" before
                    // if meet "*" previously, and the *s != *p
                    // reset the p, using '*' to match this situation
                    p = last_p;
                    s = ++last_s; 
                }else{
                    // *p is not wildcard char, 
                    // doesn't match *s, 
                    // there are no '*' wildcard matched before
                    return false;
                }
            }
            //edge case: "s" is done, but "p" still have chars.
            while (*p == '*') p++;
            return *p == '\0';
        }
};

#if 0
isMatch("aa","a")  false
isMatch("aa","aa") true
isMatch("aaa","aa") false
isMatch("aa", "*")  true
isMatch("aa", "a*") true
isMatch("ab", "?*") true
isMatch("aab", "c*a*b") false
#endif


int main()
{
    Solution sl;
    //cout << sl.isMatch("aa","a") << endl;
    //cout << sl.isMatch("aa","aa") << endl;
    //cout << sl.isMatch("aaa","aa")<< endl;
    //cout << sl.isMatch("aa", "a*")<< endl;
    //cout << sl.isMatch("aa", ".*") << endl;
    //cout << sl.isMatch("ab", ".*")<< endl;
    //cout << sl.isMatch("aab", "c*a*b")<< endl;
    cout << sl.isMatch("bacccbbbbb", "*ba**bbbb") << endl;
    //cout << sl.isMatch("babaabbbbbaaaaabbaababbaaaaaaabbaabaabbbabbaabbbbb", "*ba**bbbb");

    return 0;
}

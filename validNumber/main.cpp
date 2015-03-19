#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

#if 0
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true


1. a negtive number
2. a decimal
3. scientific notation:  x3y

#endif


class Solution {
    enum ALLOW_POS_NEG {ALLOW_NONE, ALLOW_POS, ALLOW_NEG, ALLOW_ALL};
    public:
        bool isInt(string s, enum ALLOW_POS_NEG allow = ALLOW_NONE, bool allowEmpty = false) 
        {
            size_t n = s.size();

            cout << "s:\t" << s << endl;
            int start = 0;
            if(allow == ALLOW_POS)
            {
                if(s[0] == '+')
                {
                    start ++;
                }
            }
            else if(allow == ALLOW_NEG)
            {
                if(s[0] == '-')
                {
                    start ++;
                }
            }
            else if(allow == ALLOW_ALL)
            {
                if(s[0] == '+' || s[0] == '-')
                {
                    start ++;
                }
            }
            else //ALLOW_NONE
                ;

            if(start == n)
            {
                if(allowEmpty == true)
                    return true;
                else
                    return false;
            }

            for(int i = start; i < n; i++)
            {
                if(s[i] >= '0' && s[i] <= '9')
                    ;
                else
                    return false;
            }
            return true;
        }

        bool isNumber(string s) 
        {
            size_t n = s.size();
            if(n == 0)
                return false;
            
            int start = 0, end = n-1;
            
            // skip space
            while(start < n && s[start] == ' ')
            {
                start++;
            }

            // skip '-'
            //if(s[start] == '-' || s[start] == '+')
            //    start ++;

            if(start == n)
                return false;

            // skip space
            while(s[end] == ' ')
            {
               end-- ; 
            }
            
            string newStr = s.substr(start, end - start +1);

            size_t foundE = newStr.find('e');

            //cout << "newStr\t" << newStr << endl;
            //cout << "foundE\t" << foundE<< endl;

            if (foundE != string::npos)// find 'e'
            {
                if(foundE == 0 || foundE == newStr.size()-1)
                    return false;

                size_t foundPoint = newStr.find('.');
                //cout << "foundPoint\t" << foundPoint << endl;
                if (foundPoint != string::npos)// find '.'
                {
                    if(foundPoint >= foundE)
                        return false;
                    if(foundPoint == 0) // ex ".1e34"
                        return isInt(newStr.substr(foundPoint+1, foundE-foundPoint-1), ALLOW_NONE)
                            && isInt(newStr.substr(foundE+1), ALLOW_ALL) ; 
                    if(foundPoint == foundE-1) // ex "3.e40"
                        return isInt(newStr.substr(0, foundPoint), ALLOW_ALL)
                            && isInt(newStr.substr(foundE+1), ALLOW_ALL) ; 
                    
                    return isInt(newStr.substr(0, foundPoint), ALLOW_ALL, true)
                        && isInt(newStr.substr(foundPoint+1, foundE-foundPoint-1), ALLOW_NONE)
                        && isInt(newStr.substr(foundE+1), ALLOW_ALL) ; 
                }
                else
                    return isInt(newStr.substr(0, foundE), ALLOW_ALL)
                        && isInt(newStr.substr(foundE+1), ALLOW_ALL); 
            }
            else
            {
                size_t foundPoint = newStr.find('.');
                //cout << "foundPoint\t" << foundPoint << endl;
                if (foundPoint != string::npos)// find '.'
                {
                    if(foundPoint == 0)
                        return isInt(newStr.substr(foundPoint+1), ALLOW_NONE) ; 
                    else if(foundPoint == newStr.size()-1)
                        return isInt(newStr.substr(0,foundPoint), ALLOW_ALL) ; 
                    else
                        return isInt(newStr.substr(0, foundPoint), ALLOW_ALL, true)
                            && isInt(newStr.substr(foundPoint+1), ALLOW_NONE) ; 
                }
                else
                    return isInt(newStr, ALLOW_ALL);
            }


        }
};

#if 0
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
#endif

int main()
{

    Solution sl;

#if 0
    cout << sl.isNumber("0") << endl;
    cout << sl.isNumber("1 ") << endl;
    cout << sl.isNumber("1. ") << endl;
    cout << sl.isNumber(".1 ") << endl;
    cout << sl.isNumber(". ") << endl;
    cout << sl.isNumber(" 0.1") << endl;
    cout << sl.isNumber("abc") << endl;
    cout << sl.isNumber("1 a") << endl;
    cout << sl.isNumber("2.223e10") << endl;
    cout << sl.isNumber(" 005047e+6") << endl;
    cout << sl.isNumber("+++") << endl;
    cout << sl.isNumber("4e+") << endl;
    cout << sl.isNumber(".-4") << endl;
#endif
    cout << sl.isNumber("+.8") << endl;

    return 0;
}

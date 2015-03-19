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

class Solution {
    public:
        int lengthOfLastWord(const char *s)
        {
            const char *p = s;
            int len = 0;

            p = s;
            while(*p != '\0')
            {
                if(*p == ' ')
                {
                    if(*(p+1) != ' ' && *(p+1) != '\0')
                        len = 0;
                }
                else
                    len ++;
                p++;
            }

            return len;
        }
};

int main()
{
    Solution sl;
//    cout << sl.lengthOfLastWord("hello worldd") << endl;
    cout << sl.lengthOfLastWord("ab ") << endl;

    return 0;
}

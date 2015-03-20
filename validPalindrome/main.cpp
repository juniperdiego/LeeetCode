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
        bool isPalindrome(string s) {
            if(s.empty())
                return true;

            int idx1 = 0;
            int idx2 = s.size()-1;

            while(idx1 < idx2)
            {
                while(!isalnum(s[idx1]) && idx1 < idx2)
                {
                    idx1 ++;
                }

                while(!isalnum(s[idx2]) && idx1 < idx2)
                {
                    idx2 --;
                }

                if(idx1 >= idx2)
                    break;

                if(toupper(s[idx1]) == toupper(s[idx2]))
                {
                    idx1 ++;
                    idx2 --;
                }
                else
                    return false;
            }
            return true;

        }
};
#if 0
//C++ 11
class Solution {
    public:
        bool isPalindrome(string s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            auto left = s.begin(), right = prev(s.end());
            while (left < right) {
                if (!::isalnum(*left)) ++left;
                else if (!::isalnum(*right)) --right;
                else if (*left != *right) return false;
            }
            return true;
        }
};
#endif

int main()
{


    Solution sl;
    cout << sl.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sl.isPalindrome("race a car") << endl;

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Hide Tags Hash Table Two Pointers String
#endif

class Solution {
    public:
        string minWindow(string S, string T)
        {
            if(S.empty() || T.empty() || S.size() < T.size())
                return string();

            vector<int> expect(256, 0);
            vector<int> appear(256, 0);

            for(int i = 0; i < T.size(); i++)
            {
                expect[T[i]] ++;
            }

            int minWidth = INT_MAX, min_start = 0; // 窗口大小，起点
            int win_start = 0;
            int appearCharCnt = 0;
            for(int win_end = 0; win_end < S.size(); win_end++)
            {
                appear[S[win_end]]++;
                if(appear[S[win_end]] <= expect[S[win_end]])
                    appearCharCnt ++;
                //cout << "appearCharCnt\t" <<appearCharCnt<< endl;
                if(appearCharCnt == T.size())
                {
                    // 收缩头指针
                    while (appear[S[win_start]] > expect[S[win_start]]
                          ) {
                        appear[S[win_start]]--;
                        win_start++;
                    }
                    if ((win_end - win_start + 1) < minWidth) {
                        minWidth = win_end - win_start + 1;
                        min_start = win_start;
                        //cout << "min_start\t" <<min_start << endl;
                        //cout << "min_width\t" <<minWidth<< endl;
                    }
                }
            }

            if (minWidth == INT_MAX)
                return "";
            else
                return S.substr(min_start, minWidth);
            

        }
};

int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    
    Solution sl;
    cout << sl.minWindow(S, T) << endl;
    return 0;
}

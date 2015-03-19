#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* root)
{
    while(root)
    {
        cout << root->val<< "\t" ;
        root = root->next;
    }
    cout << "NULL" ;
    cout << endl;
}


#if 0
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
            / \
            a   t
                To scramble the string, we may choose any non-leaf node and swap its two children.

                For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
            / \
            a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

rgtae
/    \
rg    tae
/ \    /  \
r   g  ta  e
        / \
       t   a
                                        We say that "rgtae" is a scrambled string of "great".

                                        Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

                                        Show Tags

 #endif

class Solution {
    public:
#if 0
        map<string, bool>  cache;
        bool isScramble(string s1, string s2) {
            cache.clear();
            return isScrambleInternal(s1, s2);
        }

        bool isScrambleInternal(string s1, string s2) {
            //cout << "s1\t" << s1 << endl;
            //cout << "s2\t" << s2 << endl;
            if(s1.size() != s2.size())
                return false;
            if(s1 == s2)
                return true;
            int s1Size = s1.size();
            int s2Size = s2.size();
            int s1aSize;
            int s1bSize;

            for(s1aSize = 1;s1aSize < s1Size ; s1aSize++ )
            {
                s1bSize =  s1Size - s1aSize;

                if( (getOrUpdate(s1.substr(0,s1aSize), s2.substr(0,s1aSize)) &&
                            getOrUpdate(s1.substr(s1aSize, s1bSize), s2.substr(s1aSize, s1bSize))) 
                        || (getOrUpdate(s1.substr(0,s1aSize), s2.substr(s1bSize,s1aSize)) &&
                            getOrUpdate(s1.substr(s1aSize, s1bSize), s2.substr(0, s1bSize))) )
                {
                    return true;
                }
            }
            return false;
        }

        bool getOrUpdate(string str1, string str2)
        {
            string str = str1 + str2;
            if(cache.count(str))
                return cache[str];

            bool res = isScrambleInternal(str1, str2);
            cache[str1+str2] = res;
            cache[str2+str1] = res;
            //cout << "str1\t" << str1<< endl;
            //cout << "str2\t" << str2<< endl;
            //cout << "res\t" << res<< endl;
            return res;
        }
#endif
        bool isScramble(string s1, string s2) {
            const int N = s1.size();
            if(N != s2.size())
                return false;

            // f[n][i][j]，表示长度为 n，起点为 s1[i] 和
            // 起点为 s2[j] 两个字符串是否互为 scramble
            //f[n][i][j]} = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
            bool f[N+1][N][N];
            //fill_n(f, (N+1)*N*N, false); // this is wrong
            fill_n(&f[0][0][0], (N+1)*N*N, false);

            // initialize f[1][i][j]
            for(int i = 0; i< N; i++)
            {
                for(int j = 0; j< N; j++)
                {
                    if(s1[i] == s2[j])
                    {
                        f[1][i][j] = true;
                    }
                }
            }

            for(int n = 2; n<= N; n++)
            {
                for(int i = 0; i+n <= N; i++)
                {
                    for(int j = 0; j+n <= N; j++)
                    {
                        for(int k = 1; k < n; k++)
                        {
                            if( (f[k][i][j] && f[n-k][i+k][j+k]) 
                                    || (f[k][i][j+n-k] && f[n-k][i+k][j]))
                            {
                                f[n][i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }
            return f[N][0][0];
            

        }
};



int main()
{
    Solution sl;
    cout << sl.isScramble("great", "rgtae") << endl;
    cout << sl.isScramble("great", "rgeat") << endl;
    cout << sl.isScramble("aa", "ab") << endl;

    return 0;
}

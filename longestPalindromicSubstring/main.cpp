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
DP, and the state transfer:

    f(i, j) = ture; if i == j
             S[i] == S[j] ,if j = i + 1
             S[i] == S[j] and f(i + 1, j - 1) ,if  j > i + 1
#endif

class Solution {
    public:
#if 1
        string longestPalindrome(string s) 
        {
            size_t len = s.size();
            char f[len][len];
            size_t start = 0;
            size_t max = 0;

            memset(f,0,sizeof(f));

            for(int i = 0; i < len; i++)
            {
                for(int j = 0; j <= i; j++)
                {
                    if((j == i) || (i == (j+1) && s[i] == s[j])
                            || ((i > (j + 1)) && s[i] == s[j] && f[j+1][i-1]))
                    {
                        f[j][i] = 1;
                        cout << "f["<<j<<"][" <<i<<"]\n";

                        if((i - j +1) > max)
                        {
                            start = j;
                            max = i - j + 1;
                        //    cout << "start\t" <<start <<endl;
                        //    cout << "max\t" <<max<<endl;
                        }
                    }
                }
            }
            return s.substr(start, max);
        }
#else
        string longestPalindrome(string s) {
            const int n = s.size();
            bool f[n][n];
            fill_n(&f[0][0], n * n, false);
            // 用 vector 会超时
            //vector<vector<bool> > f(n, vector<bool>(n, false));
            size_t max_len = 1, start = 0; // 最长回文子串的长度，起点
            for (size_t i = 0; i < s.size(); i++) {
                f[i][i] = true;
                for (size_t j = 0; j < i; j++) { // [j, i]
                    f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                    if (f[j][i] && max_len < (i - j + 1)) {
                        max_len = i - j + 1;
                        start = j;
                    }
                }
            }
            for(size_t i = 0; i < n; i++)
                for(size_t j = 0; j < n; j++)
                {
                    if(f[j][i])
                        cout << "f["<<j<<"][" <<i<<"]\n";
                }
            return s.substr(start, max_len);
        }
#endif
};

void printLCS(string str1, string str2, vector<vector<int> >flag, int idx1, int idx2)
{

    if(idx1 == 0 || idx2 == 0 )
        return;
    if(flag[idx1][idx2] == 1)
    {
        printLCS(str1, str2,flag, idx1-1, idx2-1);
        cout << idx1 <<"\t"<< idx2 <<"\t";
        cout << str1[idx1-1] <<"\t"<<endl;
    }
    else if(flag[idx1][idx2] == 2)
        printLCS(str1, str2,flag, idx1, idx2-1);
    else if(flag[idx1][idx2] == 3)
        printLCS(str1, str2,flag, idx1-1, idx2);
}

int lcs(string str1, string str2)
{
    const size_t len1 = str1.size();
    const size_t len2 = str2.size();

    if(len1 == 0 || len2 == 0)
        return 0;

    int f[len1 + 1][len2 + 1];
    vector<vector<int> >flag;
    vector<int> tmp;
    tmp.resize(len2+1);
    for(size_t i = 0; i<= len1; i++)
        flag.push_back(tmp);

    //memset(flag,0,sizeof(flag)); // 1: leftup; 2: left; 3: up
    for(size_t i = 0; i <= len1; i++)
    {
        f[i][0] = 0;
    }
    for(size_t i = 0; i <= len2; i++)
    {
        f[0][i] = 0;
    }

    for(size_t i = 1; i <= len1; i++)
    {
        for(size_t j = 1; j <= len2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                f[i][j] = f[i-1][j-1] + 1;
                flag[i][j] = 1;
            }
            else
            {
                f[i][j] = max(f[i][j-1], f[i-1][j]);
                if(f[i][j-1] > f[i-1][j])
                    flag[i][j] = 2;
                else
                    flag[i][j] = 3;
            }
        }
    }
#if 0
    for(size_t i = 1; i <= len1; i++)
    {
        for(size_t j = 1; j <= len2; j++)
        {
            //cout << "f["<<j<<"][" <<i<<"]" << f[j][i] <<"\n";
            cout << f[i][j] <<"\t";
        }
        cout << endl;
    }
    cout << endl;
    for(size_t i = 1; i <= len1; i++)
    {
        for(size_t j = 1; j <= len2; j++)
        {
            //cout << "f["<<j<<"][" <<i<<"]" << f[j][i] <<"\n";
            cout << flag[i][j] <<"\t";
        }
        cout << endl;
    }
#endif
    printLCS(str1, str2, flag, len1, len2);
    return f[len1][len2];

}



int main()
{
    string str = "aaabaaaa";
    Solution sl;
    //cout << sl.longestPalindrome(str) << endl;;
    string str1 = "abcf";
    string str2 = "bcef";
    cout << lcs(str1, str2) <<endl;;

}

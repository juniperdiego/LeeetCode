#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

void printArray(bool *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

#if 0
class Solution {
    private:
            vector<vector<string> >   m_res;
    public:
        vector<vector<string> > partition(string s) 
        {
            size_t size = s.size();
            if(size == 0)
                return m_res;

            vector<string> str;
            dfs(s, 0, size - 1, str);
            return m_res;
        }

        void dfs(string s, size_t begin, size_t end, vector<string>& str)
        {
            if(begin > end)
            {
                m_res.push_back(str);
                return;
            }

            for(size_t i = begin; i<=  end; i++)
            {
                if(isPalindrome(s, begin, i))
                {
                    str.push_back(s.substr(begin, i-begin + 1));
                    dfs(s, i+1, end, str);
                    str.pop_back();
                }
            }
        }

        bool isPalindrome(string s, size_t begin, size_t end)
        {
            if(begin == end)
                return true;
            while(begin <= end)
            {
                if(s[begin] == s[end])
                {
                    begin++;
                    end --;
                }
                else
                    return false;
            }
            return true;
        }
};

#endif


#if 1
class Solution {
    public:
        vector<vector<string> > partition(string s) {
            const int n = s.size();
            bool p[n][n]; // whether s[i,j] is palindrome
            fill_n(&p[0][0], n * n, false);
            for (int i = n - 1; i >= 0; --i)
                for (int j = i; j < n; ++j)
                    p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);


            vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j)
                    if (p[i][j]) {
                        const string palindrome = s.substr(i, j - i + 1);
                        if (j + 1 < n) {
                            for (int k = 0; k < sub_palins[j + 1].size(); k++) {
                                vector<string> v = sub_palins[j+1][k];
                                v.insert(v.begin(), palindrome);
                                sub_palins[i].push_back(v);
                            }
                        } else {
                            vector<string> v;
                            v.push_back(palindrome);
                            sub_palins[i].push_back(v);
                        }
                    }
            }

            for( int i = n -1; i >=0; i--)
            {
                cout << "sub_palins[" << i << "]:" << endl;
                vector<vector<string> > strMatrix = sub_palins[i];
                for(int j = 0; j < strMatrix.size(); j++)
                {
                    vector<string> strVec = strMatrix[j];
                    for(int k = 0; k < strVec.size(); k++)
                        cout << strVec[k] <<"\t";
                    cout << endl;
                }
            }
            return sub_palins[0];
        }
};
#endif

#if 0
class Solution {
    public:
        vector<vector<string> > partition(string s) {
            const int n = s.size();
            bool p[n][n]; // 1. whether s[i,j] is palindrome 
            fill_n(&p[0][0], n * n, false);
            for (int i = n - 1; i >= 0; --i)
                for (int j = i; j < n; ++j)
                    p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]); //第一步DP的核心递推式
            vector<vector<string> > sub_palins[n]; // 2. 要存下所有的结果，sub_palins[i]:sub palindromes of s[i, n-1]
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i; j < n; ++j)
                    if (p[i][j]) {//s[i,j] is palindrome
                        const string palindrome = s.substr(i, j - i + 1);//substr(pos, len)
                        if (j + 1 < n) {
                            for (auto v : sub_palins[j + 1]) { //在sub_palins[j + 1]中元素加上palindrome，生成sub_palins[i]中的元素
                                v.insert(v.begin(), palindrome);//第二步DP的核心递推式
                                sub_palins[i].push_back(v);
                            }
                        } else {
                            sub_palins[i].push_back(vector<string> { palindrome });//C++11大法好！
                        }
                    }
            }

            for( int i = n -1; i >=0; i--)
            {
                cout << "matrix[" << i << "]:" << endl;
                vector<vector<string> > strMatrix = sub_palins[i];
                for(int j = 0; j < strMatrix.size(); j++)
                {
                    vector<string> strVec = strMatrix[j];
                    for(int k = 0; k < strVec.size(); k++)
                        cout << strVec[k] <<"\t";
                    cout << endl;
                }
            }

            return sub_palins[0];
        }
};
#endif

int main()
{
    vector<vector<string> > res;
    string s = "aabcc";

    Solution sl;
    res = sl.partition(s);
    for(size_t i = 0; i< res.size(); i++)
    {
        printVector(res[i]);
    }

    cout << endl;
    return 0;
}



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


void isPalindrome(string s) 
{
    const int n = s.size();
    bool p[n][n]; // whether s[i,j] is palindrome
    fill_n(&p[0][0], n * n, false);
    for (int j = 0; j < n; j++)
        for (int i = 0; i <=j; i++)
            p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);
}


int main()
{
    vector<vector<string> > res;
    string s = "aabcc";

    cout << endl;
    isPalindrome2(s);
    cout << endl;

    Solution sl;
    res = sl.partition(s);
    for(size_t i = 0; i< res.size(); i++)
    {
        printVector(res[i]);
    }

    cout << endl;
    return 0;
}


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
                            for (auto v : sub_palins[j + 1]) {
                                v.insert(v.begin(), palindrome);
                                sub_palins[i].push_back(v);
                            }
                        } else {
                            sub_palins[i].push_back(vector<string> { palindrome });
                        }
                    }
            }
            return sub_palins[0];
        }
};

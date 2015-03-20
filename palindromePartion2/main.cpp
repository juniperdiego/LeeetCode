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
    public:
        int minCut(string s) {

            const int n = s.size();
            bool p[n][n]; // whether s[i,j] is palindrome
            fill_n(&p[0][0], n * n, false);
            for (int i = n - 1; i >= 0; --i)
                for (int j = i; j < n; ++j)
                    p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);

            int f[n]; // s[i,n-1] has cut number
            for (int i = 0; i < n; ++i) 
            {
                f[i] = n-1-i;
            }

            for (int i = n - 1; i >= 0; --i) 
            {
                for (int j = i; j < n; ++j)
                {
                    if(p[i][j])
                    {
                        if(j == n-1)
                            f[i] = 0;
                         else
                             f[i] = min(f[j+1]+1, f[i]);
                    }
                }
            }

#if 0
            for (int i = 0; i < n; ++i) 
            {
                cout << f[i] << "\t";
            }
            cout << endl;
#endif
            return f[0];
        }
};


int main()
{
    string s = "aabcc";

    Solution sl;
    cout << sl.minCut(s);

    cout << endl;
    return 0;
}



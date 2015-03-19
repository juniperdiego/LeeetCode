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

#if 0
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

class Solution {
    public:

        bool dfs(int idx1, int idx2,int idx3, string s1, string s2, string s3)
        {
            //cout << "idx1\t" << idx1 << endl;
            //cout << "idx2\t" << idx2 << endl;
            //cout << "idx3\t" << idx3 << endl;
            if(idx3 == s3.size())
            {
                if( idx2 == s2.size() && idx1 == s1.size())
                    return true;
                else
                    return false;
            }
            if(s1[idx1] == s3[idx3] && dfs(idx1+1,idx2,idx3+1,s1,s2,s3))
                return true;
            if(s2[idx2] == s3[idx3] && dfs(idx1,idx2+1,idx3+1,s1,s2,s3))
                return true;
            return false;
        }
        
        bool isInterleave(string s1, string s2, string s3)
        {
            if((s1.size() + s2.size()) != s3.size())
                return false;
            return dfs(0,0,0,s1,s2,s3);
        }
};
#endif

class Solution {
    public:
        
        bool isInterleave(string s1, string s2, string s3)
        {
            if((s1.size() + s2.size()) != s3.size())
                return false;
            //f[i][j] indicates s1[0 ~ i-1] and s2[0 ~ j-1] can consititue s3[0 ~ i+j-1]
            vector<bool> tmp(s2.size() + 1 ,false);//colum size
            vector<vector<bool> >  f(s1.size() + 1, tmp);//row size
            
            f[0][0] = true;// indicate null str + null str can constitue null str

            for(int i = 1; i <=s2.size(); i++ )
            {
                if(f[0][i-1] && s2[i-1] == s3[i-1])
                    f[0][i] = true;
            }

            for(int i = 1; i <=s1.size(); i++ )
            {
                if(f[i-1][0] && s1[i-1] == s3[i-1])
                    f[i][0] = true;
            }

            for(int i = 1; i <= s1.size(); i++)
            {
                for(int j = 1; j <= s2.size(); j++)
                {
                    if((f[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                            (f[i][j-1] && s2[j-1] == s3[i+j-1])) 
                            f[i][j] = true;
                }
            }
            return f[s1.size()][s2.size()];

        }
};


int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    Solution sl;
    cout << sl.isInterleave(s1, s2, "aadbbcbcac") << endl;
    cout << sl.isInterleave(s1, s2, "aadbbcbccc") << endl;
    cout << sl.isInterleave("", "", "a") << endl;
    cout << sl.isInterleave("a", "", "a") << endl;


    return 0;
}

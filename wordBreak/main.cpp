#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
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

class Solution {
    public:
        bool wordBreak(string s, set<string> &dict) 
        {
            return wordBreak(s,0, dict);
        }

        // DFS
        bool wordBreak(string s, int start, set<string> & dict)
        {
            size_t size =  s.size();
            if(size == 0) return false;
            if(start >= size)
                return true;

            for( int i = start; i <size; i++)
            {
                string str = s.substr(start, i-start+1);
                if(dict.find(str) != dict.end())
                {
                    if(wordBreak(s,i+1, dict))
                       return true;
                }

            }
            return false;
        }

        // DP
#if 1
bool wordBreak2(string s, set<string> &dict) {
    vector<bool> f(s.size() + 1, false);
    f[0] = true; 
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                f[i] = true;
                break;
            }
        }
    }
    return f[s.size()];
}
#endif

        bool wordBreak3(string s, set<string> &dict) 
        {
            size_t size =  s.size();
            if(size == 0) return false;

            vector<bool> f;
            f.resize(size + 1, false);

            f[0] = true;// empty str
            
            for( int i = 0; i <size; i++)
            {
                for(int j = i; j >=0; j--)
                {
                    string str = s.substr(j, i-j+1);
                    if(  f[j] == true && dict.find(str) != dict.end())
                    {
                        cout << "ture" << endl;
                        f[i+1] = true;
                        break;
                    }
                }
                cout <<endl<< "==============" <<endl;
            }
            return f[size];
        }
};


int main()
{
    string s = "leetcode";
    set<string> dict;
    dict.insert("leet");
    dict.insert("code");
    Solution sl;
    cout << sl.wordBreak( s, dict) <<endl;
    cout << sl.wordBreak2( s, dict)<<endl;
    cout << sl.wordBreak3( s, dict)<<endl;
    cout <<endl<< "==============" <<endl;

    cout << endl;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <limits.h>
using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

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

class Solution {
    unordered_map<string, int> m_map;
    public:
        void initMap(vector<string> &L)
        {
            m_map.clear();
            for(size_t i = 0; i <L.size() ; i++)
            {
                if(m_map.find(L[i]) == m_map.end())  
                    m_map[L[i]] = 1;  
                else
                    m_map [L[i]]++;  
            }
        }
#if 0
        void printMap()
        {
            map<string,int>::iterator it;
            for(it = m_map.begin(); it != m_map.end(); it++)
            {
                cout << it->first << "\t-->\t" << it->second << endl;
            }
            cout << endl;
        }
#endif

        vector<int> findSubstring(string S, vector<string> &L)
        {
            vector<int> result;
            if(L.size() == 0) 
                return result;

            size_t wordLen = L[0].size();
            size_t wordNum = L.size();
            size_t wordsLen = wordLen * wordNum;

            if(S.size() < wordsLen)
                return result;

            //cout << "wordLen \t" << wordLen << endl;
            //cout << "wordNum \t" << wordNum<< endl;
            //cout << "wordsLen\t" << wordsLen << endl;

            initMap(L);
            //printMap();
            
            for(size_t i = 0; i <= S.size() - wordsLen; i++)
            {
                size_t j = i;
                for( /**/; j < (i + wordsLen); j += wordLen)
                {
                    //cout << "j\t" << j << endl;
                    //printMap();
                    string tmp = S.substr(j, wordLen);
                    if(m_map.find(tmp) != m_map.end() && m_map[tmp] > 0)  
                    {
                        m_map[tmp]--;
                    }
                    else
                    {
                        break;
                    }
                }
                //cout << "==j\t" << j << endl;
                if(j >= (i+wordsLen))
                {
                    result.push_back(i);
                }
                initMap(L);
            }
            return result;

        }
};


int main()
{

    string S;
    vector<string> L;
    //s = "barbarfoobarthefoobarman";
    //L.push_back("foo");
    //L.push_back("bar");
    //L.push_back("bar");
    S = "a";
    L.push_back("a");

    vector<int> result;;
    Solution    sl;
    result = sl.findSubstring(S,L) ;
    printVector(result);

    //cout << INT_MAX << endl;
    //cout << INT_MIN << endl;
    //cout << sl.divide(100,10) << endl; 
    //cout << sl.divide(100,-10) << endl; 
    //cout << sl.divide(INT_MAX,1) << endl; 
    //cout << sl.divide(INT_MIN,-1) << endl; 
    //cout << sl.divide(INT_MIN,1) << endl; 



    return 0;
}

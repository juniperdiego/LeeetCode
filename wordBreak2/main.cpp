#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
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

template<typename T>
void printVector(vector<T> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

class Solution {
    private:
        // DFS
        void wordBreak(string s, int start, set<string> & dict)
        {
            size_t size =  s.size();
            if(size == 0) 
                return;
            if(start >= size)
            {
                string tmpStr;
                for(int i = 0; i < m_str.size(); i++)
                {
                    if(i == m_str.size() - 1)
                        tmpStr += m_str[i];
                    else
                        tmpStr += m_str[i] + " ";
                }
                m_strs.push_back(tmpStr);
            }

            for( int i = start; i <size; i++)
            {
                string str = s.substr(start, i-start+1);
                if(dict.find(str) != dict.end())
                {
                    m_str.push_back(str);
                    wordBreak(s,i+1, dict);
                    m_str.pop_back();
                }

            }
        }

    public:
        void breakWord(vector<string> &res, string &s, unordered_set<string> &dict, string str, int start, vector<bool> &f) {

            if(f[start] == false) return ;
            if(start >= s.size())
                res.push_back(str);


            for(int i = start; i <s.size(); i++)
            {
                string subStr = s.substr(start, i-start + 1);
               // cout <<"i \t" <<i << "\tj\t" << i-start<<"\t"<<subStr << endl;
                if(dict.count(subStr))
                {
                    if(str.empty())
                        breakWord(res,s,dict, subStr, i+1,f);
                    else
                        breakWord(res,s,dict, str+" "+subStr, i+1,f);
                }

            }
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
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

            vector<string> res;
            if (f[s.size()]) 
                breakWord(res, s, dict, "", 0, f);
            return res;
        }

        vector<string> wordBreak1(string s, set<string>& wordDict) {
            m_str.clear();
            m_strs.clear();

            wordBreak(s,0, wordDict);

            return m_strs;
        }
        vector<string> wordBreak2(string s, set<string> &dict) {
            vector<bool> f(s.size() + 1, false);
            vector<string> tmpStrVec;
            vector<vector<string> > map(s.size()+ 1, tmpStrVec);
            f[0] = true; 
            for (int i = 1; i <= s.size(); ++i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    string subStr = s.substr(j, i-j);
                    if (f[j] && dict.find(subStr) != dict.end())
                    {
                        f[i] = true;
                        vector<string> strVec = map[j];
                        if(strVec.size() == 0)
                        {
                            strVec.push_back(subStr);
                            map[i] = strVec;
                        }
                        else
                        {
                            for(int k = 0; k < strVec.size(); k++)
                            {
                                strVec[k] += " " + subStr ;
                                map[i].push_back(strVec[k]);
                            }
                        }
                    }   
                }   
            }   
            return map[s.size()];
        }
   private:
        vector<string> m_str; 
        vector<string> m_strs; 
};


#if 0
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
#endif

int main()
{
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");

    Solution sl;
    //vector<string> rtn =  sl.wordBreak(s, dict);
    vector<string> rtn =  sl.wordBreak(s, dict);
    printVector(rtn);
    return 0;
}

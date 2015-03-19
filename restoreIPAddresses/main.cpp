#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


#if 0
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
#endif

class Solution {
    vector<string> m_res;
    vector<string> m_str;
    public:
        void dfs(int dep, string s)
        {
            //printVector(m_str);
            if(m_str.size() > 4)
                return;
            if(m_str.size() == 4 && dep < s.size())
                return;
                
            if(dep == s.size())
            {
                if(m_str.size() == 4)
                {
                    string tmpStr;
                    for(int i = 0; i < 3; i++)
                    {
                        tmpStr += (m_str[i] + ".");
                    }
                    tmpStr += m_str[3];
                    m_res.push_back(tmpStr);
                }
                return;
            }

            for(int i = 1; i <= 3; i++)
            {
                if((dep+i-1) >= s.size())
                    break;
                if(i == 2)
                {
                    if(s[dep] == '0')
                        break;
                }
                else if(i == 3)
                {
                    if(s[dep] == '1' || 
                            (s[dep] == '2' && (s[dep+1] <= '4' || (s[dep+1] == '5' && s[dep+2] < '6'))))
                        ;
                    else
                        break;
                }
                m_str.push_back(s.substr(dep, i));
                dfs(dep + i, s);
                m_str.pop_back();
            }
            

        }
        vector<string> restoreIpAddresses(string s)
        {
            m_res.clear();
            m_str.clear();
            dfs(0, s);
            return m_res;
        }
};


int main()
{
    Solution sl;
    vector<string> out =  sl.restoreIpAddresses("25525511135");
    printVector(out);

    out =  sl.restoreIpAddresses("010010");
    printVector(out);
    return 0;
}

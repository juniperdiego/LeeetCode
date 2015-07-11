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

class Solution {
    private:
        int string2Int(const string& str)
        {
            if(str.size() == 0)
                return 0;

            int rtn = 0;
            for(int i = 0; i < str.size(); i++)
            {
                rtn = rtn*10 + (str[i] - '0');
            }
            return rtn;
        }

        vector<int> string2Ints(const string& str)
        {
            vector<int> rtn;
            if(str.size() == 0)
                return rtn;

            int size = str.size();
            int left = 0;

            int tmp;
            for(int i = 0; i < size; i++)
            {
                if(str[i] == '.')
                {
                    tmp = string2Int(str.substr(left, i - left ));
                    rtn.push_back(tmp);
                    left = i + 1;
                }
            }
            tmp = string2Int(str.substr(left, size + 1 - left ));
            rtn.push_back(tmp);
            return rtn;
            
        }
    public:
        int compareVersion(string version1, string version2)
        {
            if(version1 == version2)
                return false;
            vector<int> rtn1 = string2Ints(version1);
            vector<int> rtn2 = string2Ints(version2);

            //printVector(rtn1);
            //printVector(rtn2);
            int size = min(rtn1.size(), rtn2.size());
            for(int i = 0; i < size; i++)
            {
                if(rtn1[i] > rtn2[i] )
                    return 1;
                else if(rtn1[i] < rtn2[i] )
                    return -1;
            }
            if(rtn1.size() == rtn2.size())
                return 0;
            else if(rtn1.size() > rtn2.size())
            {
                for(int i = size; i < rtn1.size(); i++)
                {
                    if(rtn1[i] != 0)
                        return 1;
                }
                return 0;//all is zero
            }
            else //if(rtn1.size() < rtn2.size())
            {
                for(int i = size; i < rtn2.size(); i++)
                {
                    if(rtn2[i] != 0)
                        return -1;
                }
                return 0;//all is zero
            }
        }
};


int main()
{
    string str1 = "0.1";
    string str2 = "1.1";
    string str3 = "1";
    string str4 = "1.0";

    Solution sl;
    //cout << sl. compareVersion(str1, str2) << endl;
    //cout << sl. compareVersion(str2, str3) << endl;
    cout << sl. compareVersion(str3, str4) << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

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

bool myfunction (string str1,string str2) 
{ 
    str1.append(str2);
    str2.append(str1);

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] > str2[i])
            return true;
        else if(str1[i] < str2[i])
            return false;
    }
    return false;
#if 0
    int size1 = str1.size();
    int size2 = str2.size();
    int size = (size1 < size2) ? size1: size2;

    for(int i = 0; i < size; i++)
    {
        if(str1[i] > str2[i])
            return true;
        else if(str1[i] < str2[i])
            return false;
    }

    if(size < size1)
    {
        for(int i = 0; i < size1 - size; i++)
        {
            if(str1[i+ size] > str2[i])
                return true;
            else if(str1[i+ size] < str2[i])
                return false;
        }
    }
    else if(size < size2)
    {
        for(int i = 0; i < size2 - size; i++)
        {
            if(str2[i+ size] > str1[i])
                return false;
            else if(str2[i+ size] < str2[i])
                return true;
        }
    }
    return false;

#endif
    
}



class Solution {
    public:
        string largestNumber(vector<int> &num) {
           vector<string> strs;
           string result;
           
           for(int i = 0; i < num.size(); i++)
           {
                int tmp = num[i];
                int remainder = 0;
                string str;
                while(1)
                {
                    remainder = tmp%10;
                    str.push_back(remainder+'0');
                    tmp = tmp/10;
                    if(tmp == 0)
                        break;
                }
                reverse(str.begin(), str.end());
                strs.push_back(str);
           }
           sort(strs.begin(), strs.end(), myfunction);
           for(int i = 0; i< strs.size(); i++)
           {
                result.append(strs[i]);
                cout << strs[i] <<"\t";
           }

            int noZeroIdx = 0;;
            for(int i = 0; i < result.size(); i++)
            {
                if(result[i] == '0')
                    noZeroIdx++ ;
                else
                    break;
            }
            if(noZeroIdx == result.size())
            {   
                result.clear();
                result.append("0");
            }
            else
                result = result.substr(noZeroIdx);
           return result;
        }
};

int main()
{
    vector<int> num;
    num.push_back(3);
    num.push_back(30);
    num.push_back(34);
    num.push_back(5);
    num.push_back(9);
    Solution  sl;
    cout << sl.largestNumber(num) <<endl;

    num.clear();
    num.push_back(121);
    num.push_back(12);
    cout << sl.largestNumber(num) <<endl;


    num.clear();
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(8);
    num.push_back(9);
    num.push_back(0);
    cout << sl.largestNumber(num) <<endl;

    num.clear();
    num.push_back(0);
    num.push_back(0);
    cout << sl.largestNumber(num) <<endl;

}

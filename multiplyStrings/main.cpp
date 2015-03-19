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

class Solution {
    public:
        vector<int> string2IntVector(const string & num)
        {
            vector<int> ret;
            size_t len = num.size(); 
            ret.resize(len);
            for(int i = 0; i < len; i++)
            {
                ret[i] = num[i] - '0';
            }

            return ret;
        }

        string intVector2String(const vector<int> num)
        {
            string ret;
            size_t len = num.size(); 
            for(int i = 0; i < len; i++)
            {
                ret += num[i] + '0';
            }

            return ret;
        }

        string add(string num1, string num2) 
        {
            int len1 = num1.size();
            int len2 = num2.size();

            vector<int> n1 = string2IntVector(num1); 
            vector<int> n2 = string2IntVector(num2); 

            reverse(n1.begin(), n1.end());
            reverse(n2.begin(), n2.end());

            printVector(n1);
            printVector(n2);
            vector<int> ret; 

            int idx = 0;
            int carry = 0;
            while(idx < min(len1, len2))
            {
                //first calculate, then update carry flag
                ret.push_back((n1[idx] + n2[idx] + carry)%10);
                carry = (n1[idx] + n2[idx] + carry)/10;
                idx++;
            }

            while(idx < len1)
            {
                ret.push_back((n1[idx] + carry)%10);
                carry = (n1[idx] + carry)/10;
                idx++;
            }

            while(idx < len2)
            {
                ret.push_back((n2[idx] + carry)%10);
                carry = (n2[idx] + carry)/10;
                idx++;
            }

            reverse(ret.begin(), ret.end());
            return intVector2String(ret);
        }

        string multiply(string num1, string num2) 
        {
            int len1 = num1.size();
            int len2 = num2.size();

            vector<int> n1 = string2IntVector(num1); 
            vector<int> n2 = string2IntVector(num2); 

            reverse(n1.begin(), n1.end());
            reverse(n2.begin(), n2.end());

            printVector(n1);
            printVector(n2);
            vector<int> ret; 

            ret.resize(len1 + len2);
            
            for(int i = 0; i < len1; i++)
            {
                for(int j = 0; j < len2; j++)
                {
                    ret[i+j] += n1[i] * n2[j];
                    ret[i+j+1] += ret[i+j]/10;
                    ret[i+j] = ret[i+j]%10;
                }
            }

            //delete useless 0
            int ZeroNum = 0;
            for(int i = len1 + len2 -1; i >= 0 ;i--)
            {
                if(ret[i] == 0)
                    ZeroNum ++;
                else
                    break;
            }
            ret.resize(len1 + len2 - ZeroNum);

            reverse(ret.begin(), ret.end());
            return intVector2String(ret);
        }
};


int main()
{
    string str1 = "12345";
    string str2 = "234567";
    Solution sl;
    cout << sl.multiply(str1, str2) << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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

#if 0
罗马数字是由字符I,V,X,L,C,D,M等等表示的，其中
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
接下来应该是V开始的重复，但是上面要加一个横线，表示对应数字的1000倍。
个位应该是：I,II,III,IV,V,VI,VII,VIII,IX
十位应该是：X,XX,XXX,XL,L,LX,LXX,LXXX,XC
百位应该是：C,CC,CCC,CD,D,DC,DCC,DCCC,CM
#endif


class Solution {
    public:  
        int romanToInt(string s) 
        {        // Note: The Solution object is instantiated only once and is reused by each test case.
            int result=0;     
            map<char,int> roman;  
            roman['I']=1;   
            roman['V']=5; 
            roman['X']=10;   
            roman['L']=50; 
            roman['C']=100;     
            roman['D']=500;   
            roman['M']=1000;   
            for(int i=s.length()-1;i>=0;i--)    
            {         
                if(i==s.length()-1)   
                {           
                    result=roman[s[i]];     
                    continue;
                }
                if(roman[s[i]] >= roman[s[i+1]])     
                    result+=roman[s[i]];            
                else  
                    result-=roman[s[i]];    
            } 
            return result;  
        }
};

int main()
{

    Solution    sl;

    cout << sl.romanToInt("MMMCDLVI") <<endl;

    return 0;
}

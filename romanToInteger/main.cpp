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
�������������ַ�I,V,X,L,C,D,M�ȵȱ�ʾ�ģ�����
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;
������Ӧ����V��ʼ���ظ�����������Ҫ��һ�����ߣ���ʾ��Ӧ���ֵ�1000����
��λӦ���ǣ�I,II,III,IV,V,VI,VII,VIII,IX
ʮλӦ���ǣ�X,XX,XXX,XL,L,LX,LXX,LXXX,XC
��λӦ���ǣ�C,CC,CCC,CD,D,DC,DCC,DCCC,CM
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

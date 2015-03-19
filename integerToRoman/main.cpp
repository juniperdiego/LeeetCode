#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
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

string romans[4][10] =
{
    {"","I", "II","III","IV","V","VI","VII","VIII","IX" },
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
    {"","M","MM","MMM"}
};

class Solution {
    public:
        string digitToRoman(int digit, int pow)
        {
            return romans[pow][digit]; 
        }

        string intToRoman(int num)
        {
            int base = 1000;
            int digit = 0;
            int pow = 4 - 1;
            string result;

            while(num)
            {
                digit = num/base;
                result += digitToRoman(digit, pow);
                num = num%base;
                base /= 10;
                pow --;
            }
            return result;

        }
};

int main()
{

    Solution    sl;

    cout << sl.intToRoman(1234) <<endl;
    cout << sl.intToRoman(3456) <<endl;

    return 0;
}

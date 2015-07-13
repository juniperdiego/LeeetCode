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
        string convertToTitle(int n) {
            string str;
            int a = 0;
            while(n)
            {
                a = (n-1) % 26;
                str += char(a + 'A');
                n = (n-1)/26;
            }
            reverse(str.begin(), str.end());
            return str;
        }
};

#if 0
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
#endif


int main()
{
    Solution sl;
    cout << sl.convertToTitle(1) <<endl;
    cout << sl.convertToTitle(100) <<endl;
    cout << sl.convertToTitle(1000) <<endl;

    cout << endl;
    return 0;
}

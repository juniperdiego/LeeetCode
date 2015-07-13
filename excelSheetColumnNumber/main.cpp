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
        int titleToNumber(string s) {

            int num = 0;
            for(int i = 0; i < s.size(); i++)
            {
                num = num * 26 + (s[i] - 'A' + 1);
            }
            return num;

        }
};
#if 0
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
#endif


int main()
{
    Solution sl;
    cout << sl.titleToNumber("A") <<endl;
    cout << sl.titleToNumber("Z") <<endl;
    cout << sl.titleToNumber("AB") <<endl;

    cout << endl;
    return 0;
}

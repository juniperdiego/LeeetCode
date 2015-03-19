#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>

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
        int jump(int A[], int n)
        {
            vector<int> f;
            f.resize(n);
            f[0] = 0;
            for(int i = 1; i < n; i++)
                f[i] = INT_MAX;
            
            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j < i; j++)
                {
                    if(A[j] >= (i-j))// can jump from j to i 
                        f[i] = min(f[i], f[j] + 1);
                }
            }
            return f[n-1];

        }
};


int main()
{
//    int A[] = {2,3,1,1,4};
    int A[] = {3,4,3,2,5,4,3};
    Solution sl;
    cout << sl.jump(A, sizeof(A)/sizeof(int)) << endl;

    return 0;
}

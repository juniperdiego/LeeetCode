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
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
#endif

class Solution {
    public:
        int jump(int A[], int n) {
            if(A[0] == 0) return 0;
            int maxReach = 0;// the most rigth we can reach
            
            int steps = 0;
            
            for(int i = 0; i <= maxReach ; /* i++ */)//i means current position
            {
                steps ++;
                int newMaxReach = 0;
                for(int j = i; j <= maxReach && j < n; j++ )// count i
                {
                    if(A[j] + j > newMaxReach)
                    {
                        newMaxReach = A[j] + j;
                        i = j + 1; // begin with j+1
                    }
                }

                if(newMaxReach >= n-1)
                {
                    return steps;
                }
                else if(newMaxReach > maxReach)
                {
                    // update the maxReach
                    maxReach = newMaxReach;
                }
            }

            return steps;

        }
};


int main()
{

    int A[] = {2,3,1,1,4};
    int B[] = {2,1};

    Solution sl;

    cout << sl.jump(A, sizeof(A)/sizeof(A[0])) << endl;
    cout << sl.jump(B, sizeof(B)/sizeof(B[0])) << endl;

    return 0;
}

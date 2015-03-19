#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>
#include <limits.h>

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

class Solution {
    public:
#if 0
        int searchInsert(int A[], int n, int target)
        {
            int i;
            for( i = 0; i < n; i++)
            {
                if(A[i] >= target)
                    return i; 
            }
            return i;
        }
#endif
        int searchInsert(int A[], int n, int target)
        {
            return binarySearch(A, 0, n-1, target);
        }

        int binarySearch(int A[], int left, int right, int target)
        {
            if(left == right)
            {
                if(A[left] >= target)
                    return left;
                else
                    return right + 1;
            }
            int mid = (left + right)/2;
            
            if(A[mid] == target)
                return mid;
            if(A[mid] > target)//mid may be the answer
                return binarySearch(A, left, mid , target);
            if(A[mid] < target)
                return binarySearch(A, mid+1, right, target);
        }
};


int main()
{
# if 0
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
#endif
    int A[] = {1,3,5,6};

    Solution sl;
    cout << sl.searchInsert(A, sizeof(A)/sizeof(int), 5) << endl;
    cout << sl.searchInsert(A, sizeof(A)/sizeof(int), 2) << endl;
    cout << sl.searchInsert(A, sizeof(A)/sizeof(int), 7) << endl;
    cout << sl.searchInsert(A, sizeof(A)/sizeof(int), 0) << endl;
}

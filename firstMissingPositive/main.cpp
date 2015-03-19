#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
#if 0
        int firstMissingPositive(int A[], int n) 
        {
            vector<int> B;
            B.resize(n + 1);

            //cout << "n\t" << n << endl;
            //printArray(A, n);
            for(int i = 0; i < n; i++)
            {
                if(A[i] <= n && A[i] >0)
                {
                    // do A[i]'s value as B's index
                    B[A[i]] = 1;
                }
            }
            //printVector(B);

            for(size_t i = 1; i < B.size(); i++)
            {
                if(B[i] != 1)
                    return i;
            }
            return  n+1;
        }
#endif
        int firstMissingPositive(int A[], int n) 
        {
            int i = 0;
            int tmp;
            // A[i] should store (i + 1)
            // it means A[0] stores 1, A[1] stores 2, ...

            while(i < n)
            {
                // A[0~n-1] only can store 1~n;
                // A[i] should store i + 1
                // A[i] != i +1 menas A[i] should be move to others, but A[i] should be moved where?
                // A[i] should be move to A[A[i]-1]
                // i.e.: {3, 1, 4, -1}
                // A[0]= 3, != (0+1), so 3 shoule be moved. moved to A[A[0] -1] =2
                // so swap 3 and 4, then the array is {4, 1, 3 , -1}
                // but 4 also doesn't appear at A[0], so go on to swap, until the condition doens't meet, then i++
                if(A[i] <= n && A[i] >0 && A[i] != (i+1) && A[A[i] - 1] != A[i] )
                {
                    tmp = A[i];
                    A[i] = A[tmp - 1]; 
                    A[tmp - 1] = tmp;
                }
                else
                    i++;
            }
            printArray(A, n);

            for(int i = 0; i < n; i++)
            {
                if(A[i] != (i+1) )
                    return i + 1;
            }
            return n+1;

        }
};


int main()
{
    int A[] = {1,2,0};
    int B[] = {3,4,-1,1};

    Solution sl;
    cout << sl.firstMissingPositive(A, sizeof(A)/sizeof(int)) << endl;
    cout << sl.firstMissingPositive(B, sizeof(B)/sizeof(int)) << endl;

    return 0;
}

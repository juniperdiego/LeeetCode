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

class Solution {
    public:
        void merge(int A[], int m, int B[], int n)
        {
            int index = m + n - 1;
            m--;
            n--;

            while(m >= 0 && n >= 0)
            {
                if(A[m] > B[n])
                {
                    A[index] = A[m];
                    m--;
                }
                else
                {
                    A[index] = B[n];
                    n--;
                }
                index--;
            }
            while(n >= 0)
            {
                A[index] = B[n];
                n--;
                index--;
            }

        }
};


int main()
{
    int A[10] = {11,13 ,15 ,17 ,19 };
    int B[] = {2, 4 ,6 ,8 ,10};

    Solution sl;
    printArray(A, sizeof(A)/sizeof(A[0]));
    sl.merge(A, 5, B, sizeof(B)/sizeof(B[0]));
    printArray(A, sizeof(A)/sizeof(A[0]) );
    return 0;
}

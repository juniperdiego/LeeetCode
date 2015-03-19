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

class Solution 
{
    public: 
        int first_small(int* array, int low, int high, int key )
        {
            int mid = 0;
            while(low < high)
            {   
                mid =  (low + high + 1)/2;
                //if(array[mid] ==  key)
                //    return mid;
                if(array[mid] > key)
                    high = mid - 1;
                else
                    low = mid;

            }
            return low;

        }

};


int main()
{
    int a[] = {1,3,5,7,10,11,16,20};
    int b[] = {0,1,2,3,4, 5, 6, 7};
    Solution sl;
    
    printArray(a, sizeof(a)/sizeof(a[0]));
    printArray(b, sizeof(b)/sizeof(b[0]));
    int res;
    res =  sl.first_small(a, 0, sizeof(a)/sizeof(a[0]) -1, 1 );
    cout << 1 << "\t index = " << res <<endl;

    res =  sl.first_small(a, 0, sizeof(a)/sizeof(a[0]) -1, 4 );
    cout << 4 << "\t index = " << res <<endl;

    res =  sl.first_small(a, 0, sizeof(a)/sizeof(a[0]) -1, 9 );
    cout << 9 << "\t index = " << res <<endl;

    res =  sl.first_small(a, 0, sizeof(a)/sizeof(a[0]) -1, 16);
    cout << 16 << "\t index = " << res <<endl;

    res =  sl.first_small(a, 0, sizeof(a)/sizeof(a[0]) -1, 20);
    cout << 20 << "\t index = " << res <<endl;


    return 0;
}

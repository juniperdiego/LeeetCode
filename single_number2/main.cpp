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
        int singleNumber(int A[], int n)
        {    
            vector<int> cnt;
            int width = sizeof(int)*8;
            cnt.resize(width, 0); 
            int res = 0;

            for(int i  = 0; i< n; i++)
            {   
                for(int j  = 0; j< width; j++)
                {   
                    cnt[j] += (A[i] >> j) & 0x1;
                    //cnt[j] %= 3;
                }   

            }   
            for(int j  = 0; j< width; j++)
            {   
                //cout << "j :\t" <<j <<"\t cnt\t"<< cnt[j]<<endl;
                if(cnt[j]%3 != 0)
                    res ^=  ( 1 << j); 
            }   
            return res;
        }   
} ;


int main()
{

    int a[] = {2,2,3,2};
    Solution sl;
    int res = sl.singleNumber(a, sizeof(a)/sizeof(a[0]));
    cout <<endl<< "==============" <<endl;
    cout <<res << endl;
    return 0;
}

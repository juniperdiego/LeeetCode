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

void printArray(int *numsay, int size)
{
    for(int i = 0; i < size; i++)
        cout << numsay[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<int> numsay )
{
    for(int i = 0; i <numsay.size(); i++)
        cout << numsay[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<string> numsay )
{
    for(int i = 0; i <numsay.size(); i++)
        cout << numsay[i]<< "\t" ;
    cout << endl;
}

class Solution {
    public:
        int findPeakElement(vector<int>& nums)
        {
            if(nums.size() == 0)
                return -1;
            if(nums.size() == 1)
                return 0;
            if(nums[0] > nums[1])
                return 0;

            int size = nums.size();
            if(nums[size - 1] > nums[size - 2])
                return size - 1;

            int low = 1;
            int high = size - 2;
            int mid;

            while(low < high)
            {  
                mid = (low + high)/2;
                if(nums[mid] < nums[mid+1])
                {  
                    low = mid+1;
                }  
                else if(nums[mid] < nums[mid-1])
                {  
                    high = mid-1;
                }  
                else
                    return mid;
            }
            return low;


        }
};


int main()
{

    Solution sl;
#if 0
    cout << sl.pow(2, 0) << endl;
    cout << sl.pow(2, 1) << endl;
    cout << sl.pow(2, 2) << endl;
    cout << sl.pow(2, 3) << endl;
    cout << sl.pow(2, 4) << endl;
    cout << sl.pow(2, 5) << endl;
    cout << sl.pow(2, -5) << endl;
    cout << sl.pow(1, -5) << endl;
    cout << sl.pow(1, INT_MIN) << endl;
    cout << sl.pow(1, INT_MAX) << endl;
#endif

    return 0;
}

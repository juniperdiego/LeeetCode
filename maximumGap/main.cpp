#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
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
        int maximumGap(vector<int>& nums) 
        {
            int n = nums.size();
            if(n == 0 || n == 1)
                return 0;

            int maxVal = nums[0];
            int minVal = nums[0];

            for(int i = 1; i < n; i++)
            {
                maxVal = max(maxVal, nums[i]);
                minVal = min(minVal, nums[i]);
            }

            // n nums has (n-1) the gap ;
            // average gap = (maxVal - minVal) / (n-1);
            // so the minimum of max gap is ceilOf(average gap);
            int minOfMaxGap = ceil((double)(maxVal - minVal) /(n - 1));

            // bucket number, the last bucket may contains the maxVal 
            // 如果能整除，那么maxVal再最后一个bucket,
            // 如果不能整除，那么maxVal在倒数第二个bucket
            int bucketCnt = ceil((double)(maxVal - minVal)/minOfMaxGap) + 1;

            // for numbers in a same bucket, its max gap is minOfMaxGap,
            // So the maxGap occur at different buckets, including emtpy buckets

            // we record maxVal and minVal in every bucket 
            vector<int> maxVec(bucketCnt, INT_MIN);
            vector<int> minVec(bucketCnt, INT_MAX);

            int idx = 0;
            for(int i = 0; i < n; i ++)
            {
                idx = (nums[i] - minVal)/minOfMaxGap;
                if(maxVec[idx] < nums[i])
                    maxVec[idx] = nums[i];
                if(minVec[idx] > nums[i])
                    minVec[idx] = nums[i];
            }

            //cout << "minOfMaxGap\t" << minOfMaxGap << endl;
            //cout << "bucketCnt\t"<< bucketCnt<< endl;
            //cout << "maxVec\t";
            //printVector(maxVec);
            //cout << "minVec\t";
            //printVector(minVec);

            int maxGap = minOfMaxGap;
            int preMax = maxVec[0];
            for(int i = 1; i < bucketCnt; i++)
            {
                if(minVec[i] == INT_MAX)// empty bucket
                    continue;
                if(minVec[i] - preMax > maxGap)
                {
                    maxGap = minVec[i] - preMax;
                }

                preMax = maxVec[i];
            }

            return maxGap; 

        }
};

int main()
{
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(1);

    Solution sl;

    cout << sl.maximumGap(nums) <<endl;
    return 0;
}

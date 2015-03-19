#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

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
        int maxArea(vector<int> &height) {

            size_t size = height.size();
            size_t low = 0;
            size_t high = size - 1;
            int area = 0;
            int maxArea = 0;

            while(low < high)
            {
                area = min(height[low], height[high]) * (high-low);
                maxArea = max(area, maxArea);
                if(height[low] < height[high])
                {
                    low++;
                }
                else
                {
                    high --;
                }
            }

            return maxArea;
        }
};

int main()
{

    Solution    sl;

    //cout << sl.minDepth(&t[0]) <<endl;

    return 0;
}

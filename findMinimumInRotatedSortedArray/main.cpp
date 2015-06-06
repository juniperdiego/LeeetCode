#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

struct TreeNode {
    int val;    
    TreeNode *left;  
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};

void preorder(TreeNode * root)
{
    if(root == NULL) return;
    cout << root->val << "\t" ;
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode * root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << "\t" ;
    inorder(root->right);
}

void postorder(TreeNode * root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\t" ;
}

class Solution {
    public:
        int findMin1(vector<int>& A) 
        {
            int low = 0;
            int high = A.size() - 1;

            int mid = 0;
            // A[low] > A[high] ensure the pivot is between low and high
            while(low < high && A[low] > A[high])
            {
                //if there only two elements, just return A[high], find pivot
                if(low + 1 == high)
                    return A[high];

                mid = (low + high)/2;

                //cout << "low\t" << low<< endl; 
                //cout << "high\t" << high << endl; 
                //cout << "mid\t" << mid<< endl; 

                if(A[low] < A[mid])//pivot is in bottom half, mid can't be lowest
                {
                    low = mid + 1;
                }
                else //pivot is in first half, mid may be lowest
                {
                    high = mid;
                }
            }

            // this case: vecotr A is Sorted Array , not rotated, so just return A[low]
            return A[low];
        }

        int findMin(vector<int>& A) 
        {
            int low = 0;
            int high = A.size() - 1;

            int mid = 0;
            // A[low] > A[high] ensure the pivot is between low and high
            while(low < high && A[low] > A[high])
            {

                mid = (low + high)/2;

                //cout << "low\t" << low<< endl; 
                //cout << "high\t" << high << endl; 
                //cout << "mid\t" << mid<< endl; 

                if(A[low] < A[mid])//pivot is in bottom half, mid can't be lowest
                {
                    low = mid + 1;
                }
                else if(A[low] == A[mid])//there only two elements
                {
                    //if there only two elements, just return A[high], find pivot
                    return A[high];
                }
                else //pivot is in first half, mid may be lowest
                {
                    high = mid;
                }
            }

            // this case: vecotr A is Sorted Array , not rotated, so just return A[low]
            return A[low];
        }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    //A.push_back(6);

    Solution sl;
    cout << sl.findMin(A) << endl;

    return 0;
}

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
        TreeNode *sortedArrayToBST(vector<int> &num)
        {
            int size = num.size();
            if(size == 0)
                return NULL;
             return sortedArrayToBSTInternal(num, 0, size - 1);

        }

        TreeNode *sortedArrayToBSTInternal(vector<int> &num, int low, int high)
        {

            // the code is very important, i.e: low = 4, hight = 5, mid = 4, 
            // will call sortedArrayToBSTInternal(num, 4, 3)
            if(low > high)
                return NULL;
            if(low == high)
                return new TreeNode(num[low]); 

            int mid = (high-low)/2 + low;
            cout << mid << endl;
            TreeNode *root = new TreeNode(num[mid]); 
            TreeNode *left = sortedArrayToBSTInternal(num, low, mid - 1);
            TreeNode *right = sortedArrayToBSTInternal(num, mid + 1, high);
            root->left = left;
            root->right= right;
            return root;
        }
};

int main()
{
    vector<int> num;

    for(int i = 0; i < 100; i ++)
    {
        num.push_back(i);
    }

    Solution sl;
    TreeNode* root = sl.sortedArrayToBST(num);
    inorder(root);

    return 0;
}

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
    vector<vector<int> > m_res;
    vector<int>  m_vec;
    public:
        void dfs(TreeNode * root, int sum)
        {
            if(root == NULL)
                return;
            if(root->left == NULL && root->right == NULL)
            {
                if(root->val == sum)
                {
                    m_vec.push_back(root->val);
                    m_res.push_back(m_vec);
                    m_vec.pop_back();
                }
                return;
            }

            m_vec.push_back(root->val);
            if(root->left)
            {
                dfs(root->left, sum-root->val);
            }
            if(root->right)
            {
                dfs(root->right, sum-root->val);
            }
            m_vec.pop_back();
        }

        vector<vector<int> > pathSum(TreeNode *root, int sum)
        {
            m_vec.clear();
            m_res.clear();

            dfs(root, sum);
            return m_res;
        }
};

#if 0
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
       5
      / \
     4   8
    /   / \
   11  13  4
  /  \    / \
 7    2  5   1

 return
 [
 [5,4,11,2],
 [5,8,4,5]
 
#endif
int main()
{
    TreeNode n0(5);
    TreeNode n1(4);
    TreeNode n2(8);
    TreeNode n3(11);
    TreeNode n4(13);
    TreeNode n5(4);
    TreeNode n6(7);
    TreeNode n7(2);
    TreeNode n8(5);
    TreeNode n9(1);


    n0.left = &n1;
    n0.right= &n2;
    n1.left = &n3;
    n2.left = &n4;
    n2.right= &n5;
    n3.left = &n6;
    n3.right= &n7;
    n5.left = &n8;
    n5.right= &n9;

    Solution sl;
    vector<vector<int> > res= sl.pathSum(&n0, 22);

    for(int i = 0; i < res.size(); i++)
    {
        printVector(res[i]);
    }

    return 0;
}

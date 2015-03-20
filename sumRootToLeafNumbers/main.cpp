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
    private:
        int  m_sum;
        vector<int> m_vec;

        int intVec2Int(vector<int> nums)
        {
            int num = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                num = num * 10 + nums[i];
            }
            return num;
        }

        void dfs(TreeNode* root)
        {
            if(root == NULL)
                return;

            m_vec.push_back(root->val);

            if(root->left == NULL && root->right == NULL)
            {
                m_sum += intVec2Int(m_vec);
                m_vec.pop_back();
                return;
            }

            if(root->left)
                dfs(root->left);
            if(root->right)
                dfs(root->right);
            m_vec.pop_back();

        }
    public:
        int sumNumbers(TreeNode *root)
        {
            m_vec.clear();
            m_sum = 0;
            dfs(root);
            return m_sum;
        }
};

int main()
{
    TreeNode node0(4);
    TreeNode node1(2);
    TreeNode node2(7);
    TreeNode node3(1);
    TreeNode node4(3);
    TreeNode node5(5);
    TreeNode node6(8);

    node0.left = &node1;
    node0.right= &node2;

    node1.left = &node3;
    node1.right= &node4;

    node2.left = &node5;
    node2.right= &node6;

    Solution sl;
    int res = sl.sumNumbers(&node0);
    cout << res;

    cout << endl;
    return 0;
}

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
        int m_sum;
    public:
        int dfs(TreeNode * root)
        {
            if(root == NULL)
                return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            int sum = root->val;
            if(l > 0) 
                sum += l;
            if(r > 0) 
                sum += r;
#if 0
            cout << "l\t" << l << endl;
            cout << "r\t" << r << endl;
            cout << "root\t" << root->val << endl;
            cout << "sum\t" << sum<< endl;
#endif
            m_sum = max(m_sum, sum);

            if(max(l, r) > 0)
                return max(l, r) + root->val;
            else
                return root->val;
        }


        int maxPathSum(TreeNode *root) 
        {
            m_sum = INT_MIN;
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
    cout <<sl.maxPathSum(&node0);
    cout << endl;
    return 0;
}

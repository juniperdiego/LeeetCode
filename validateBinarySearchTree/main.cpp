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

#if 0
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            vector<int> result;
            stack<TreeNode*> st;

            TreeNode* p = root;

            // inorder traverse
            while(p != NULL || st.size() != 0)
            {
                while(p != NULL)
                {
                    st.push(p);
                    p = p->left;
                }

                if(!st.empty())
                {
                    p = st.top();
                    st.pop();
                    result.push_back(p->val);
                    p = p->right;
                }
            }
            printVector(result);
            //check if it is ascend
            for(int i = 0; i < result.size()-1; i++)
            {
                if(result[i] <= result[i+1])
                ;
                else
                    return false;
            }
            return true;

        }
};
#endif
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            return isValidBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
        }
        bool isValidBST(TreeNode *root, long long min, long long max) 
        {
            if(root == NULL) return true;

            if( (root->val < max ) && (root->val > min) &&
                    isValidBST(root->left, min, root->val) &&
                    isValidBST(root->right, root->val, max) 
              )
                return true;
            else
                return false;
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
    bool re = sl.isValidBST(&node0);

    cout << "rueslut ========" <<endl;
    cout << re;
    cout << endl;
    return 0;
}

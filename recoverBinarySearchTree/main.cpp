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
        void recoverTree(TreeNode *root) {
            vector<TreeNode*> result;
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
                    result.push_back(p);
                    p = p->right;
                }
            }

            TreeNode* r1 = NULL, *r2 = NULL;
            for(int i = 0; i < result.size()-1; i++)
            {
                if(result[i]->val  > result[i+1]->val)
                {
                    r1 = result[i];
                    break;
                }
            }

            for(int i = result.size()-1; i >= 1; i--)
            {
                if(result[i]->val < result[i-1]->val)
                {
                    r2 = result[i];
                    break;
                }
            }
            //swap r1 and r2's value

            int tmp = r1->val;
            r1->val = r2->val;
            r2->val = tmp;
        }
};


int main()
{
    TreeNode node0(4);
    TreeNode node1(7);
    TreeNode node2(2);
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

    inorder(&node0);
    cout << endl;
    sl.recoverTree(&node0);
    inorder(&node0);

    return 0;
}

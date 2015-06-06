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

class Solution1 {
    public:
        vector<int>  rightSideView(TreeNode *root)
        {
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            vector<int>  res;

            if(root != NULL)
            {
                q1.push(root);
            }

            while(!q1.empty())
            {
                TreeNode * p = q1.front();
                q1.pop();

                if(p->left)
                    q2.push(p->left);
                if(p->right)
                    q2.push(p->right);

                if(q1.empty() /*&& !q2.empty()*/)
                {
                    res.push_back(p->val);
                    swap(q1, q2);
                }
            }
            return res;
        }
};

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {

            vector<int> rtn;
            if(root == NULL)
                return rtn;

            queue<TreeNode*> q;

            TreeNode* pre = NULL;

            q.push(root);
            q.push(NULL);//mark the end of this level

            while(!q.empty())
            {
                TreeNode * p = q.front();
                q.pop();

                if(p == NULL) 
                {
                    rtn.push_back(pre->val);

                    if(!q.empty())// some elements still exist in q.
                        q.push(NULL);//mark end of this level

                }
                else
                {
                    if(p->left)
                        q.push(p->left);
                    if(p->right)
                        q.push(p->right);
                }
                pre = p;
            }

            return rtn;
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

    Solution1 sl;
    vector<int> res = sl.rightSideView(&node0);

    printVector(res);
    cout << endl;
    return 0;
}

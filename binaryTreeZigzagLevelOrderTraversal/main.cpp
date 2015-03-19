#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        vector<vector<int> > zigzagLevelOrder(TreeNode *root)
        {
            vector<vector<int> > res;
            if(root == NULL) 
                return res;

            queue<TreeNode*> q;
            vector<int> curVec;

            q.push(root);
            q.push(NULL); // mark the layer's end
            bool isLeft2Right = true;

            while(!q.empty())
            {
                TreeNode * p = q.front();
                q.pop();

                if(p == NULL)
                {
                    if(!isLeft2Right)
                    {
                        reverse(curVec.begin(), curVec.end());
                    }
                    res.push_back(curVec);
                    isLeft2Right = !isLeft2Right;
                    curVec.clear();
                    if(!q.empty())// if elements exist in queue
                        q.push(NULL);// mark the layer's end
                        
                }
                else
                {
                    curVec.push_back(p->val);

                    if(p->left)
                        q.push(p->left);
                    if(p->right)
                        q.push(p->right);
                }
            }
            return res;
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
    vector<vector<int> >res = sl.zigzagLevelOrder(&node0);

//    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
    {
        printVector(res[i]);
    }
    return 0;
}

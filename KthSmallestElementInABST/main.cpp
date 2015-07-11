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
        int kthSmallest(TreeNode* root, int k) {
            
            stack<TreeNode*> st;
            TreeNode* p = root;

            int cnt = 0;

            while(p != NULL || !st.empty())
            {
                while(p)
                {
                    st.push(p);
                    p = p->left;
                }

                if(!st.empty())
                {
                    p = st.top();
                    st.pop();

                    cnt ++;
                    if(cnt == k)
                    {
                        return p->val;
                    }

                    p = p->right;

                }
            }
            return -1;

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
    int res;
    res = sl.kthSmallest(&node0, 1);
    cout <<res << endl;
    res = sl.kthSmallest(&node0, 5);
    cout <<res << endl;
    res = sl.kthSmallest(&node0, 7);
    cout <<res << endl;

    return 0;
}

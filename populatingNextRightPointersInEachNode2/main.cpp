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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
        TreeLinkNode* findLeftMostOfNextLayer(TreeLinkNode * root)
        {
            if(root == NULL)
                return NULL;
            if(root->left)
                return root->left;
            if(root->right)
                return root->right;
            return findLeftMostOfNextLayer(root->next);
        }


        void connect(TreeLinkNode *root)
        {
            if(root == NULL)
                return;

            TreeLinkNode* curLayer = root;//the leftmost node of the layer

            while(curLayer)
            {
                TreeLinkNode* curNode = curLayer ;
                while(curNode)
                {
                    TreeLinkNode* left = curNode->left;
                    TreeLinkNode* right= curNode->right;
                    TreeLinkNode* next = findLeftMostOfNextLayer(curNode->next);
                    //curNode is not a leaf node
                    if(left && right)
                    {
                        left->next = right;
                    }

                    if(next)
                    {
                        if(right)
                            right->next = next;
                        else if(left)
                            left->next = next;
                    }
                    curNode = curNode->next;
                }
                curLayer = findLeftMostOfNextLayer(curLayer);

            }
        }
};

#if 0
    1
  /  \
 2    3
/ \    \
4   5    7
            After calling your function, the tree should look like:
              1 -> NULL
            /  \
           2 -> 3 -> NULL
          / \    \
         4-> 5 -> 7 -> NULL
#endif
int main()
{
    TreeLinkNode node0(1);
    TreeLinkNode node1(2);
    TreeLinkNode node2(3);
    TreeLinkNode node3(4);
    TreeLinkNode node4(5);
    TreeLinkNode node5(6);
    TreeLinkNode node6(7);

    node0.left = &node1;
    node0.right= &node2;

    node1.left = &node3;
    node1.right= &node4;

    //node2.left = &node5;
    node2.right= &node6;

    Solution sl;
    sl.connect(&node0);

    TreeLinkNode *p = &node0;
    TreeLinkNode *node = NULL;


    while(p)
    {
        node = p;
        while(node)
        {
            cout << node->val << "\t" ;
            node = node->next;
        }
        cout << endl;
        p= p ->left;
    }


    return 0;
}

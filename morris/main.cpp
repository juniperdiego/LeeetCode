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
        void morris_inorder(TreeNode* T) {
            TreeNode *p, *temp;
            p = T;
            while(p) {
                if(p->left == NULL) {
                    printf("visit %4d \n", p->val);
                    p = p->right;
                } else {
                    temp = p->left;
                    // find the most right node of the p's left node
                    while(temp->right != NULL && temp->right != p) {
                        temp = temp->right;
                    }
                    if(temp->right == NULL) {
                        cout << "build link for " << temp->val <<"-->" << p->val << endl;
                        temp->right = p;
                        p = p->left;
                    } else {
                        printf("visit %4d \n", p->val);
                        cout << "destory link for " << temp->val <<"-->" << p->val << endl;
                        temp->right = NULL;
                        p = p->right;
                    }
                }
            }
        }

        void morris_preorder(TreeNode* T) {
            TreeNode *p, *temp;
            p = T;
            while(p) {
                if(p->left == NULL) {//visit the leftmost leaf node
                    printf("visit %4d \n", p->val);
                    p = p->right;
                } else {
                    temp = p->left;
                    // find the most right node of the p's left node
                    while(temp->right != NULL && temp->right != p) {
                        temp = temp->right;
                    }
                    if(temp->right == NULL) {//build the link
                        printf("visit %4d \n", p->val);
                        temp->right = p;
                        p = p->left;
                    } else {//remove the link
                        temp->right = NULL;
                        p = p->right;
                    }
                }
            }
        }
        void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
        {
            if (from == to)
                return;
            TreeNode *x = from, *y = from->right, *z;
            while (true)
            {
                z = y->right;
                y->right = x;
                x = y;
                y = z;
                if (x == to)
                    break;
            }
        }

        void printReverse(TreeNode* from, TreeNode *to) // print the reversed tree nodes 'from' -> 'to'.
        {
            reverse(from, to);

            TreeNode *p = to;
            while (true)
            {
                printf("%d ", p->val);
                if (p == from)
                    break;
                p = p->right;
            }

            reverse(to, from);
        }

        void morris_postorder(TreeNode *root) {
            TreeNode dump(0);
            dump.left = root;
            TreeNode *cur = &dump, *temp = NULL;
            while (cur)
            {
                if (cur->left == NULL)
                {
                    cur = cur->right;
                }
                else
                {
                    temp = cur->left;
                    while (temp->right != NULL && temp->right != cur)
                        temp = temp->right;

                    if (temp->right == NULL)
                    {
                        temp->right = cur;
                        cur = cur->left;
                    }
                    else
                    {
                        printReverse(cur->left, prev);  // call print
                        temp->right = NULL;
                        cur = cur->right;
                    }
                }
            }
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
    sl.morris_inorder(&node0);
    inorder(&node0);
    cout << endl;

    sl.morris_preorder(&node0);
    preorder(&node0);
    cout << endl;

    sl.morris_postorder(&node0);
    cout << endl;
    postorder(&node0);
    cout << endl;

    return 0;
}

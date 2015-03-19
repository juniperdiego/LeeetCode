#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

class Solution 
{
    public:   
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
        {     
            return buildTree(postorder, 0, postorder.size()-1,
                              inorder, 0, inorder.size()-1);
        }

        TreeNode *buildTree(vector<int> &postorder, int low1, int high1,
                            vector<int> &inorder, int low2, int high2)
        {
            //cout << "==============" <<endl;
            //cout << "low1 = \t" << low1 <<endl;
            //cout << "high1= \t" << high1 <<endl;
            //cout << "low2 = \t" << low2 <<endl;
            //cout << "high2= \t" << high2 <<endl;
            if(low1 > high1 || low2> high2)
                return NULL;

            TreeNode * p = new TreeNode(postorder[high1]);
            if(low1 == high1)
            {
                return p;
            }
            int index = 0;
            for(index = low2; index < high2; index++)
            {
                if(inorder[index] == postorder[high1])
                    break;
            }
            //cout << "index= \t" << index<<endl;

            if(index != low2)
                p->left = buildTree(postorder, low1,(low1) + (index-1-low2), inorder, low2, index-1);
            if(index != high2)
                p->right = buildTree(postorder, (high1-1) - (high2-index-1) ,high1-1, inorder, index+1, high2);
                
            return p;
        }
} ;

int main()
{
     vector<int> pre;
     vector<int> in;
     vector<int> post;

     pre.push_back(0);
     pre.push_back(1);
     pre.push_back(3);
     pre.push_back(4);
     pre.push_back(7);
     pre.push_back(2);
     pre.push_back(5);
     pre.push_back(8);
     pre.push_back(6);


     in.push_back(3);
     in.push_back(1);
     in.push_back(7);
     in.push_back(4);
     in.push_back(0);
     in.push_back(5);
     in.push_back(8);
     in.push_back(2);
     in.push_back(6);

     post.push_back(3);
     post.push_back(7);
     post.push_back(4);
     post.push_back(1);
     post.push_back(8);
     post.push_back(5);
     post.push_back(6);
     post.push_back(2);
     post.push_back(0);

    Solution sl;
    TreeNode *r = sl.buildTree(in, post);

    cout << "======pre========" <<endl;
    preorder(r);
    cout <<endl<< "==============" <<endl;
    cout << "======in========" <<endl;
    inorder(r);
    cout <<endl<< "==============" <<endl;

    cout << "======post========" <<endl;
    postorder(r);
    cout <<endl<< "==============" <<endl;
    cout << endl;
    return 0;
}

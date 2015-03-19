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
        vector<TreeNode *> dfs(int start, int end)
        {
            vector<TreeNode*> trees;

            if(start > end)
            {
                trees.push_back(NULL);
                return trees;
            }
            if(start == end)
            {
                TreeNode* p = new TreeNode(start);
                trees.push_back(p);
                return trees;
            }

            for(int rootVal = start; rootVal <= end; rootVal ++)
            {
                vector<TreeNode*> leftSubTrees = dfs(start, rootVal - 1);
                vector<TreeNode*> rightSubTrees = dfs(rootVal + 1, end);

                int leftSubTreesNum = leftSubTrees.size();
                int rightSubTreesNum = rightSubTrees.size();
                for(int i = 0; i < leftSubTreesNum; i++)
                {
                    for(int j= 0; j< rightSubTreesNum; j++)
                    {
                        TreeNode* root = new TreeNode(rootVal);
                        TreeNode* left = leftSubTrees[i];
                        TreeNode* right= rightSubTrees[j];
                        root->left = left;
                        root->right= right;
                        trees.push_back(root);
                    }
                }
            }
            return trees;
        }
        vector<TreeNode *> generateTrees(int n) {
            if(n == 0)
            {
                vector<TreeNode *>   trees; 
                trees.push_back(NULL);
                return trees;
            }
            return dfs(1, n);
        }
};

int main()
{
    Solution sl;
    vector<TreeNode *> trees;
    //trees = sl.generateTrees(1);
    //cout << trees.size() << endl;
    //trees = sl.generateTrees(2);
    //cout << trees.size() << endl;
    trees = sl.generateTrees(3);
    cout << trees.size() << endl;
    for(int i = 0; i < trees.size(); i++)
    {
        inorder(trees[i]);
        cout << endl;
    }
    trees.clear();
    trees = sl.generateTrees(4);
    cout << trees.size() << endl;
    for(int i = 0; i < trees.size(); i++)
    {
        inorder(trees[i]);
        cout << endl;
    }
    return 0;
}

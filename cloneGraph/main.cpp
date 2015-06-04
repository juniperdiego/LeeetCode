#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(node == NULL)
                return NULL;

            map <UndirectedGraphNode*, UndirectedGraphNode*> old2New;
            queue <UndirectedGraphNode*> q;

            UndirectedGraphNode* oldNode = NULL;

            // each node in queue is already copied itself
            // but neighbors are not copied yet
            old2New[node] = new UndirectedGraphNode(node->label);
            q.push(node);

            while(!q.empty())
            {
                oldNode = q.front();   
                q.pop();

                for(int i = 0; i < oldNode->neighbors.size(); i++)
                {
                    if(oldNode->neighbors[i] != NULL)
                    {
                        if(old2New.count(oldNode->neighbors[i]) != 0)
                        {
                            old2New[oldNode]->neighbors.push_back(old2New[oldNode->neighbors[i]]);
                        }
                        else
                        {
                            UndirectedGraphNode* tmp = new UndirectedGraphNode(oldNode->neighbors[i]->label);
                            old2New[oldNode->neighbors[i]] = tmp;//build the mapping
                            old2New[oldNode]->neighbors.push_back(tmp);

                            // add it to queue after copy it if the node doesn't the map
                            q.push(oldNode->neighbors[i]);
                        }
                    }
                }
            }

            return old2New[node];
        }
};

int main()
{

    Solution sl;

    return 0;
}

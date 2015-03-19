#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(NULL), right(NULL) {}
};

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
class Solution {
    public:
        int minDepth(TreeNode *root) {
            if(NULL == root) return 0;

            queue<TreeNode*> cur, next;

            TreeNode *p = root;
            cur.push(p);
            int dep = 1;

            while( !cur.empty())
            {
                p= cur.front();
                cur.pop();

                if(p->left == NULL && p->right == NULL)
                    return dep;

                if(p->left != NULL )
                {
                    next.push(p->left);
                }

                if(p->right != NULL )
                {
                    next.push(p->left);
                }

                if(cur.empty() && !next.empty())
                {
                    swap(cur, next);
                    dep++;
                }
            }

            return dep;
        }

};

int main()
{
    TreeNode t[15];
    t[0].val = 0;
    t[1].val = 1;
    t[2].val = 2;
    t[3].val = 3;
    t[4].val = 4;
    t[5].val = 5;
    t[6].val = 6;
    t[7].val = 7;
    t[8].val = 8;
    t[9].val = 9;
    t[10].val = 10;
    t[11].val = 11;
    t[12].val = 12;
    t[13].val = 13;
    t[14].val = 14;

#if 1
    t[0].left  = &t[1];
    t[0].right = &t[2];
    t[1].left  = &t[3];
    t[1].right = &t[4];
    t[2].left  = &t[5];
    t[2].right = &t[6];
    t[3].left  = &t[7];
    t[5].left  = &t[8];
    t[8].right = &t[9];
    t[9].left  = &t[10];
    t[9].right = &t[11];
    t[10].left = &t[12];
    t[10].right = &t[13];
    t[10].right = &t[14];
#endif

    Solution    sl;

    cout << sl.minDepth(&t[0]) <<endl;

    return 0;
}

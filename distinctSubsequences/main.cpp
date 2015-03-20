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

#if 0
class Solution {
    int m_cnt;
public:
    void dfs(const string & s, const string & t, int idx1, int idx2)
    {
        if(idx2 == t.size())
        {
            m_cnt++;
            return;
        }

        if(idx1 == s.size())
            return;

        for(int i = idx1; i < s.size(); i++)
        {
            if(s[i] == t[idx2])
                dfs(s, t, i+1, idx2+1);
        }
    }

    int numDistinct(string S, string T) {
        m_cnt = 0;
        dfs(S,T,0,0);
        return m_cnt;
    }
};
#endif
class Solution {
public:

    int numDistinct(string s, string t) {
        vector<int> tmp(s.size() + 1, 0);
        vector<vector<int> > f(t.size()+1, tmp);

        //f[i][j] indicates nums that t[0,i-1] was converted by s[0,j-1]
    
        f[0][0] = 1; // null to null, only have one way

        for(int i = 1; i < s.size(); i++)// there is only one way that any string changed to null
            f[0][i] = 1;

        for(int i = 1; i < t.size(); i++)// there is no way that null to any string
            f[i][0] = 0;

        for(int j = 1; j <= s.size(); j++)
        {
            for(int i = 1; i <= t.size(); i++)
            {
                if(i > j)
                    f[i][j] = 0;
                else
                {
                    if(t[i-1] == s[j-1])
                        f[i][j] = f[i-1][j-1] + f[i][j-1];
                    else
                        f[i][j] = f[i][j-1];
                }
            }
        }
        return f[t.size()][s.size()];

    }
};

int main()
{
    string S = "rabbbit", T = "rabbit";
    Solution sl;
    cout << sl.numDistinct(S, T) << endl;

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
#include <sstream>

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
    private:
        int string2Int(const string& str)
        {
            stringstream strstrm;
            strstrm << str;
            int rtn;
            strstrm >> rtn;
            return rtn;
        }

    public:
        int evalRPN(vector<string>& tokens) {

            if(tokens.size() == 0)
                return 0;

            stack<int> st;
            int operand1;
            int operand2;
            int rtn;

            for(int i = 0; i < tokens.size(); i++)
            {
                if(tokens[i] == "+" ||
                        tokens[i] == "-" ||
                        tokens[i] == "*" ||
                        tokens[i] == "/" 
                  )
                {
                    operand2 = st.top();
                    st.pop();
                    operand1 = st.top();
                    st.pop();

                    if(tokens[i] == "+")
                        rtn = operand1 + operand2;
                    else if(tokens[i] == "-")
                        rtn = operand1 - operand2;
                    else if(tokens[i] == "*")
                        rtn = operand1 * operand2;
                    else // if(tokens[i] == "/")
                        rtn = operand1 / operand2;

                    st.push(rtn);
                }
                else
                {
                    st.push(string2Int(tokens[i]));
                }

            }
            if(!st.empty())
            {
                rtn = st.top();
                st.pop();
            }
                
            return rtn;

        }
};

#if 0
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
#endif

int main()
{
    Solution sl;
    int res;

    vector<string> tokens;
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("*");

    res = sl.evalRPN(tokens);
    cout <<res << endl;

    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    res = sl.evalRPN(tokens);
    cout <<res << endl;

    return 0;
}

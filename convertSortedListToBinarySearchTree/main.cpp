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

//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0

class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head)
        {
            vector<int> &num;
            while(head != NULL)
            {
                num.push_back(head->val);
                head = head->next;
            }
            return sortedArrayToBST(&num);
                
        }
        TreeNode *sortedArrayToBST(vector<int> &num)
        {
            int size = num.size();
            if(size == 0)
                return NULL;
             return sortedArrayToBSTInternal(num, 0, size - 1);

        }

        TreeNode *sortedArrayToBSTInternal(vector<int> &num, int low, int high)
        {

            // the code is very important, i.e: low = 4, hight = 5, mid = 4, 
            // will call sortedArrayToBSTInternal(num, 4, 3)
            if(low > high)
                return NULL;
            if(low == high)
                return new TreeNode(num[low]); 

            int mid = (high-low)/2 + low;
            cout << mid << endl;
            TreeNode *root = new TreeNode(num[mid]); 
            TreeNode *left = sortedArrayToBSTInternal(num, low, mid - 1);
            TreeNode *right = sortedArrayToBSTInternal(num, mid + 1, high);
            root->left = left;
            root->right= right;
            return root;
        }
};
#endif

class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            int len = 0;
            ListNode *p = head;
            while (p) {
                len++;
                p = p->next;
            }
            return sortedListToBST(head, 0, len - 1);
        }
    private:
        TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
            if (start > end) return NULL;
            int mid = start + (end - start) / 2;
            if(list)
                cout << "1.list->val\t" << list->val << endl;
            TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
            if(list)
                cout << "2.list->val\t" << list->val << endl;
            TreeNode *parent = new TreeNode(list->val);
            parent->left = leftChild;
            list = list->next;
            if(list)
                cout << "3.list->val\t" << list->val << endl;
            parent->right = sortedListToBST(list, mid + 1, end);
            if(list)
                cout << "4.list->val\t" << list->val << endl;
            return parent;
        }
};

int main()
{
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);


    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;

    Solution sl;
    TreeNode* root = sl.sortedListToBST(&n0);
    inorder(root);

    return 0;
}

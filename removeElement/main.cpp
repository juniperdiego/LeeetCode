#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


void printVector(vector<char> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* root)
{
    while(root)
    {
        cout << root->val<< "\t" ;
        root = root->next;
    }
    cout << "NULL" ;
    cout << endl;
}


class Solution {
    public:
        int removeElement(int A[], int n, int elem)
        {
            if(A == NULL)
                return 0;
            int idx = 0;
            cout << "n:" << n<< endl;
            for(int i = 0; i < n; i++)
            {
                cout << idx << endl;
                if(A[i] != elem)
                {
                    A[idx++] = A[i];
                }

            }
            return idx;

        }
};



int main()
{
    int A[] = {2,3,5,6,7,5,8};

    Solution sl;
    //printList(&n1);
    //printList(&m1);
    //printList(sl.merge2Lists(&n1, &m1));
    cout << (sl.removeElement(A, sizeof(A)/sizeof(int), 5)) << endl;;
    printArray(A, sizeof(A)/sizeof(int));
}

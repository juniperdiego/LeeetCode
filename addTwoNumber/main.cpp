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
    cout << endl;
}

class Solution {
    public:
        ListNode* reverseList(ListNode* root)
        {
            if(NULL == root)
                return NULL;
            ListNode* pPre = NULL;
            ListNode* pCur = root;
            ListNode* pNext = NULL;

            while(pCur)
            {
                pNext = pCur->next;
                pCur->next = pPre;

                pPre = pCur;
                pCur = pNext;
            }
            return pPre;
        }

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;

            ListNode* p1 = l1;
            ListNode* p2 = l2;
            ListNode dummy(-1);
            ListNode* pNew = &dummy;
            int carry = 0;
            int sum = 0;

            while(p1 && p2)
            {
                sum = (p1->val + p2->val + carry)%10;
                carry= (p1->val + p2->val + carry)/10;
                pNew->next = new ListNode(sum);
                pNew = pNew->next;
                p1 = p1->next;
                p2 = p2->next;
            }

            while(p1)
            {
                sum = (p1->val +  carry)%10;
                carry= (p1->val + carry)/10;
                pNew->next = new ListNode(sum);
                pNew = pNew->next;
                p1 = p1->next;
            }
            
            while(p2)
            {
                sum = (p2->val +  carry)%10;
                carry= (p2->val + carry)/10;
                pNew->next = new ListNode(sum);
                pNew = pNew->next;
                p2 = p2->next;
            }
            
            if(carry)
            {
                pNew->next = new ListNode(carry);
                pNew = pNew->next;
            }

            return dummy.next;
        }
};


int main()
{
    ListNode n0(2);
    ListNode n1(4);
    ListNode n2(3);
    n0.next = &n1;
    n1.next = &n2;

    ListNode m0(5);
    ListNode m1(6);
    ListNode m2(6);
    ListNode m3(3);
    m0.next = &m1;
    m1.next = &m2;
    m2.next = &m3;

    Solution sl;
    printList(&n0);
    printList(&m0);
    //printList(sl.reverse(&n0));
    printList(sl.addTwoNumbers(&n0, &m0));
}

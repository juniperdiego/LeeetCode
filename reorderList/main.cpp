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

#if 0
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
#endif

class Solution {
    public:
        void reorderList(ListNode* head)
        {
            if(head == NULL)
                return ;

            ListNode* pFront = head;
            stack<ListNode*> st;
            int totalNum = 0;
            int curNum = 0;

            while(pFront)
            {
                st.push(pFront);
                pFront= pFront->next;
                totalNum++;
            }

            pFront = head;
            ListNode* pRear =  NULL;

            ListNode* tmp = NULL;
            while(curNum < totalNum/2)
            {
                pRear = st.top();
                st.pop();

                tmp = pFront->next;
                pFront->next = pRear;
                pRear->next = tmp;
                pFront= tmp;
                curNum ++;
            }

            //mark the end
            pFront->next = NULL;
            
        }
};


int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
//    n4.next = &n5;
    //n5.next = &n2;

    ListNode *p = &n1;

    Solution sl;
    printList(p);
    sl.reorderList(p);
    printList(p);
}

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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #if 0
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 #endif

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) 
        {
            ListNode * p = head;
            int len = 0;

            ListNode * seg1Last = NULL;
            ListNode * seg2Last = NULL;
            ListNode * seg2Head = NULL;

            while(p != NULL)
            {
                if(p-> next == NULL)
                    seg2Last = p;
                len ++;
                p = p->next;
            }
            k = k % len;
            if(k == 0)
                return head;
            k = len - k;

            p = head;
            while(--k)
            {
                p = p->next;
            }
            seg1Last = p;
            seg2Head = p -> next;

            seg2Last -> next = head;
            seg1Last -> next = NULL;
            
            return seg2Head;

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
    n4.next = &n5;

    ListNode *p = &n1;

    Solution sl;
    printList(p);
    //printList(p = sl.rotateRight(p, 0));
    //printList(p = sl.rotateRight(p, 1));
    // printList(p = sl.rotateRight(p, 2));
    //printList(p = sl.rotateRight(p, 3));
    //printList(p = sl.rotateRight(p, 4));
    //printList(p = sl.rotateRight(p, 5));
    printList(p = sl.rotateRight(p, 6));
}

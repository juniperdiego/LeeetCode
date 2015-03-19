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
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 #endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if(head == NULL)
                return NULL;
            
            ListNode * p = head;
            ListNode dummy(-1);
            head = &dummy;

            while(p)
            {
                if(p->next == NULL || p->val != p->next->val)
                {
                    head->next = p;
                    head = p;
                    p = p->next;
                    // to break old link
                    head->next = NULL;
                }
                else
                {
                    //find the node which its value is not equla to p->val
                    // and store the node as new p;
                    p = p->next;
                    while(p)
                    {
                        if(p->next == NULL)
                        {
                            //should end
                            head->next = NULL;
                            p = NULL;// jump the outer loop
                            break;// jump the inner loop
                        }

                        if(p->val != p->next->val)   
                        {
                            p = p->next;
                            break;
                        }
                        else
                            p = p->next;
                    }
                }
                    
                #if 0
                cout << "p->val\t" << p->val << endl;
                cout << "head->val\t" << head->val << endl;
                #endif
            }
            return dummy.next;
        }
};


int main()
{
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(4);
    ListNode n4(4);
    ListNode n5(3);
    ListNode n6(3);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode *p = &n1;

    Solution sl;
    printList(p);
    printList(p = sl.deleteDuplicates(p));
}

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
class Solution {
    public:
        ListNode *reverse(ListNode* head)
        {
            if(head == NULL)
                return NULL;
            ListNode * pre = NULL;
            ListNode * cur = head;
            ListNode * next = NULL;
            
            // make cur->next = pre;
            while(cur)
            {
                next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;
            }
            return pre;
            
        }
#if 1
        ListNode* reverse(ListNode* head, ListNode* end)
        {
            if(head == NULL)
                return NULL;
            ListNode * pre = NULL;
            ListNode * cur = head;
            ListNode * next = NULL;
            
            // make cur->next = pre;
            while(cur)
            {
                next = cur->next;
                cur->next = pre;

                pre = cur;
                cur = next;

                if(pre == end)
                    break;
            }
            return pre;
            
        }
        ListNode *reverseKGroup(ListNode *head, int k)
        {
            if(head == NULL)
                return NULL;

            ListNode dummy(-1);
            dummy.next = head;

            ListNode* pre = &dummy;
            ListNode* start= head;
            ListNode* end = start;
            ListNode* next= NULL;
            int cnt = 0;
            
            while(end)
            {
                cnt++;
                if(cnt == k)
                {
                    next = end->next;
                    //assign
                    pre->next = reverse(start, end);
                    start->next = next;
                    //cout << "start\t" << start->val <<endl;
                    //cout << "end\t" << end->val <<endl;
                    printList(dummy.next);
                    printList(pre->next);

                    //update
                    pre = start;
                    start = next;
                    end = next;
                    cnt = 0;
                    //cout << "start\t" << start->val <<endl;
                    //cout << "end\t" << end->val <<endl;
                    //cout << "pre\t" << pre->val <<endl;

                }
                else
                    end = end->next;
            }
            return dummy.next;
        }
#endif
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


    ListNode m1(6);
    ListNode m2(7);
    ListNode m3(8);
    ListNode m4(9);
    ListNode m5(10);

    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &m5;

    n5.next = &m1;



    ListNode k1(0);
    ListNode k2(0);
    ListNode k3(10);
    ListNode k4(15);
    ListNode k5(20);

    k1.next = &k2;
    k2.next = &k3;
    k3.next = &k4;
    k4.next = &k5;

    vector<ListNode *> lists;
    lists.push_back(&n1);
    lists.push_back(&m1);
    lists.push_back(&k1);

    Solution sl;
    //printList(&n1);
    //printList(&m1);
    //printList(sl.merge2Lists(&n1, &m1));
    printList(&n1);
    printList(sl.reverseKGroup(&n1, 3));
}

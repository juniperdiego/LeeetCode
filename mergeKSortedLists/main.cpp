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
        ListNode *merge2Lists(ListNode* r1, ListNode* r2)
        {
            if(NULL == r1)
                return r2;
            if(NULL == r2)
                return r1;
            ListNode dummy(-1);
            ListNode *p = &dummy;
            while(r1 && r2)
            {
                if(r1->val < r2->val)
                {
                    p->next = r1;
                    r1 = r1->next;
                }
                else
                {
                    p->next = r2;
                    r2 = r2->next;
                }
                p = p->next;
            }
            if(r1) 
                p->next = r1;
            else if(r2) 
                p->next = r2;
            return dummy.next;
        }

        ListNode *mergeKListsOverTime(vector<ListNode *> &lists)
        {
            ListNode* p = NULL;
            for(size_t i = 0; i < lists.size(); i++)
            {
                p = merge2Lists(p, lists[i]);
                //printList(p);
            }
            return p;
        }
        ListNode *mergeKLists(vector<ListNode *> &lists, int beg, int end)
        {
#if 0
            cout << "beg\t" << beg << endl;
            cout << "end\t" << end << endl;
            for(size_t i = 0; i < lists.size(); i++)
                printList(lists[i]);
#endif
            if(beg == end)
                return lists[beg];
            if((end - beg) == 1)
            {
                lists[beg] = merge2Lists(lists[beg], lists[end]);
                lists[end] = NULL;
                return lists[beg];
            }
            ListNode* p1 = mergeKLists(lists, beg, (beg+end)/2);
            ListNode* p2 = mergeKLists(lists, (beg+end)/2, end);
            return merge2Lists(p1, p2);

        }
        ListNode *mergeKLists(vector<ListNode *> &lists)
        {
            if(lists.size() == 0) return NULL;
            return mergeKLists(lists, 0, lists.size()-1);
        }
};




int main()
{
    ListNode n1(1);
    ListNode n2(3);
    ListNode n3(5);
    ListNode n4(7);
    ListNode n5(9);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;


    ListNode m1(2);
    ListNode m2(4);
    ListNode m3(6);
    ListNode m4(8);
    ListNode m5(10);

    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &m5;

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
    printList(sl.mergeKLists(lists));
}

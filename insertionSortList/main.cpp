#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>
#include <limits.h>

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
        ListNode* insertionSortList(ListNode* head)
        {
            if(head == NULL)
                return NULL;

            ListNode dummy(INT_MIN);
            dummy.next = head;

            ListNode* preInsertion = NULL;
            ListNode* insertion = NULL;
            ListNode* cur = head->next;
            head->next = NULL;//break the sorted and unsorted
            ListNode* next = NULL;

            while(cur)
            {
                preInsertion = & dummy; 
                insertion = dummy.next;

                //find the right position
                while(insertion != NULL && cur->val >= insertion->val)
                {
                    preInsertion = preInsertion->next;
                    insertion = insertion->next;
                }

#if 0
                if(insertion == NULL)//cur is max, don't need to move it
                {
                    next = cur->next;//just store cur first;
                    preInsertion->next = cur; 
                    cur->next = NULL;
                    cur = next;
                }
                else
                {
                    next = cur->next;//just store cur first;
                    preInsertion->next = cur; 
                    cur->next = insertion;
                    cur = next;
                }
#endif
                next = cur->next;//just store cur first;
                preInsertion->next = cur; 
                cur->next = insertion;
                cur = next;


            }
            return dummy.next;
        }
};

int main()
{
    ListNode n1(6);
    ListNode n2(5);
    ListNode n3(4);
    ListNode n4(3);
    ListNode n5(2);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    //n5.next = &n2;

    ListNode *p = &n1;

    Solution sl;
    printList(p);
    printList(sl.insertionSortList(p));
}

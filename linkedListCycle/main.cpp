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
        bool hasCycle(ListNode *head)
        {
            if(head == NULL)
                return false;

            ListNode* slow = head->next;
            ListNode* fast = NULL;

            if(slow)
                fast = slow->next;

            while(fast && slow)
            {
                if(fast == slow)
                    return true;
                if(fast->next && fast->next->next)
                    fast = fast->next->next;
                else //reach the end
                    return false;
                slow = slow->next;
            }
            return false;
        }
};


int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(3);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n2;

    ListNode *p = &n1;

    Solution sl;
    cout << sl.hasCycle(p) << endl;
}

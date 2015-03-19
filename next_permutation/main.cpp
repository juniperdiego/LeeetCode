#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool comp(const int &a, const int &b)
{
    return a > b;
};

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i;
            vector<int>::iterator iter = num.end();
            int maxNum = INT_MIN;

            //step 1, find the first number which violate the increase form right to left, we call it AAA
            // take 5 6 7 8 4 3 2 1 for a example, find AAA = 7;
            for(i = num.size() - 2; i >= 0; i--)
            {
                if (num[i] > num[i+1])
                    break;
            }

            if (i >= 0) //i found
            {
                int j;
                int minNum = INT_MAX;
                //step 2, find the first number which is large than AAA form right to left, we call it BBB
                // take 5 6 7 8 4 3 2 1 for a example, find BBB = 8;
                for(j = num.size() - 1; j >= 0; j--)
                {
                    if (num[j] < num[i])
                        break;
                }

                //step 3, swap AAA and BBB
                // take 5 6 7 8 4 3 2 1 for a example, exchanged array is 5 6 8 7 4 3 2 1 
                int t = num[i];
                num[i] = num[j];
                num[j] = t;    

                //step 4, reverse all digit after AAA's position
                // take 5 6 7 8 4 3 2 1 for a example, exchanged array is 5 6 8 7 4 3 2 1, then reverse 7 4 3 2 1
                // the output array is 5 6 8 1 2 3 4 7
                int k = i + 1; 
                j =  num.size() - 1;
                while(k < j)
                {
                    t = num[k];
                    num[k] = num[j];
                    num[j] = t;

                    k++; 
                    j--;
                }
            }
            else
                //sort(num.begin(), num.end());            
            {
                int k = 0; 
                int j =  num.size() - 1;
                while(k < j)
                {
                    int t = num[k];
                    num[k] = num[j];
                    num[j] = t;

                    k++; 
                    j--;
                }
            }
        }
};

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

int main()
{
    int a[] = {5, 6, 7, 8, 4, 3, 2, 1};
    //int a[] = {5, 6, 7, 8};//, 4, 3, 2, 1};
    vector<int> b ;
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
#if 1
    b.push_back(4);
    b.push_back(3);
    b.push_back(2);
    b.push_back(1);
#endif

    int cnt = 0;
#if 1
    do
    {
        cnt ++;
        //printArray(a, sizeof(a)/sizeof(a[0]));
    }
    while(next_permutation(a, a + sizeof(a)/sizeof(a[0])));
#endif

    Solution sl;
    //cnt = 10;
    while(cnt-- )
    {
        printVector(b);
        sl.nextPermutation(b);
    }

    return 0;
}

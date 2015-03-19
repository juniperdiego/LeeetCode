#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

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

#if 0
class Solution {
    public: 
        int trap(int A[], int n) 
        {
            vector<int> left;
            vector<int> right;
            left.resize(n);
            right.resize(n);

            //printArray(A, n);

            left[0] == 0;
            right[n-1] == 0;
            
            // get the left's max 
            for(int i = 1; i< n;i++)
            {
                left[i] = max(left[i-1], A[i-1]);
            }
            //printVector(left);

            // get the right's max 
            for(int i = n-2; i>=0;i--)
            {
                right[i] = max(right[i+1], A[i+1]);
            }
            //printVector(right);

            // clac the trap water
            int sum =0;
            int height = 0;
            for(int i = 0; i< n;i++)
            {
                height = min(left[i], right[i]);
                if(height > A[i])
                    sum += height - A[i];
            }
            return sum;
        }

        int trap2(int A[], int n)
        {
            stack<int> st;

            for(int i = 0; i < n;)
            {
                if(st.empty() || )
            }
        }
};

#endif

struct Node
{
    int val;
    int index;
    Node(){}
    Node(int v, int idx):val(v), index(idx){}
};

#if 0
class Solution {
    public:
        int trap(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            stack<Node> s;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                int height = 0;
                while(!s.empty())
                {
                    Node node = s.top();
                    if (A[i] < node.val ) // A[] = {4, 2,3}, calc sum
                    {
                        int width = i - node.index - 1;
                        sum += A[i] * width - height * width;
                        break;
                    }
                    else
                    {
                        int width = i - node.index - 1;
                        sum += node.val * width - height * width;
                        height = node.val;// update height
                        s.pop();
                    }
                }
                s.push(Node(A[i], i));
            }

            return sum;
        }
};
class Solution {
    public:
        int trap(int a[], int n) {
            stack<pair<int, int> > s;
            int water = 0;
            for (int i = 0; i < n; ++i) {
                int height = 0;
                while (!s.empty()) {
                    int bar = s.top().first;
                    int pos = s.top().second;

                    cout << "=======================" <<endl;
                    cout << "i   = " <<i <<endl;
                    cout << "bar = " <<bar <<endl;
                    cout << "pos = " <<pos<<endl;
                    cout << "=======================" <<endl;

                    water += (min(bar, a[i]) - height) * (i - pos - 1);
                    height = bar;
                    if (a[i] < bar)
                        break;
                    else
                        s.pop(); 
                }
                s.push(make_pair(a[i], i));
            }
            return water;
        }
};


class Solution {
    public:
        int trap(int a[], int n) {
            stack<pair<int, int> > s;
            int water = 0;
            for (int i = 0; i < n; ++i) {
                int height = 0;
                while (!s.empty()) {
                    int bar = s.top().first;
                    int pos = s.top().second;

                    if (a[i] < bar)
                        break;

                    cout << "=======================" <<endl;
                    cout << "i   = " <<i <<endl;
                    cout << "bar = " <<bar <<endl;
                    cout << "pos = " <<pos<<endl;
                    cout << "i - pos - 1 " <<i - pos - 1 <<endl;
                    cout << "=======================" <<endl;

                    water += (min(bar, a[i]) - height) * (i - pos - 1);
                    height = bar;
                    s.pop(); 
                }
                s.push(make_pair(a[i], i));
            }
            return water;
        }
};
#endif
class Solution {
    public:
        int trap(int A[], int n) {
            int max = 0; 
            for(int i = 0; i < n; i++)
                if (A[i] > A[max]) max = i;
            int water = 0;
            int left_max_height = 0;
            // calc the left_max_height, at the same time update water
            for (int i = 0; i < max; i++)
                if (A[i] > left_max_height) 
                    left_max_height = A[i];
                else 
                    water += left_max_height - A[i];
            int right_max_height = 0;
            // calc the right_max_height, at the same time update water
            for (int i = n - 1; i > max; i--)
                if (A[i] > right_max_height) 
                    right_max_height = A[i];
                else 
                    water +=  right_max_height - A[i];
            return water;
        }
};
int main()
{
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int b[] = {4,2,3};
    Solution sl;
    
    int sum ;
    sum =  sl.trap(a, sizeof(a)/sizeof(a[0]));
    cout << "sum = " << sum <<endl;
    sum =  sl.trap(b, sizeof(b)/sizeof(b[0]));
    cout << "sum = " << sum <<endl;

    return 0;
}

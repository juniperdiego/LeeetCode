#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
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

class Solution {
    public:
        int maxSubArray(int A[], int n) {

            int sum = 0;
            int result = INT_MIN;
            for(int i = 0; i< n ;i++)
            {
                if(sum <= 0)
                    sum = A[i];
                else
                    sum += A[i];
                result = max(sum, result);
            }
            return result;

        }
};


int main()
{
    vector<vector<int> > triangle;
    vector<int> a;

    a.push_back(2);
    triangle.push_back(a);
    
    a.clear();
    a.push_back(3);
    a.push_back(4);
    triangle.push_back(a);

    a.clear();
    a.push_back(6);
    a.push_back(5);
    a.push_back(7);
    triangle.push_back(a);

    a.clear();
    a.push_back(4);
    a.push_back(1);
    a.push_back(8);
    a.push_back(3);
    triangle.push_back(a);

    Solution sl;
    cout << sl.minimumTotal(triangle) << endl;;
    cout <<endl<< "==============" <<endl;

    cout << endl;
    return 0;
}

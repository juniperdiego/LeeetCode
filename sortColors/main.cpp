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

class Solution {
    public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n - 1;
        printArray(A, n);
        for (int i = 0; i < blue + 1;) {
            cout << "i   = " << i<<endl;
            cout << "red = " << red<<endl;
            cout << "bule= " << blue<<endl;
            if (A[i] == 0)
            {
                swap(A[i], A[red]);
                i++;
                red++;
            }
            else if (A[i] == 2)
                swap(A[i], A[blue--]);
            else
                i++;
            cout <<endl <<endl;
            printArray(A, n);
        }
}
};

int main()
{
    int a[] = {0,1,0,2,1,0,1,2};
    int b[] = {4,2,3};
    Solution sl;
    
    sl.sortColors(a, sizeof(a)/sizeof(a[0]));

    return 0;
}

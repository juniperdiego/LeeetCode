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
        int maxProfit(vector<int> &prices) 
        {
            int res = 0;

            if(prices.size() == 0)
                return res;

            for(int i = 1; i < prices.size(); i++)
            {
                if(prices[i] > prices[i-1])
                    res += ( prices[i] - prices[i-1]);
            }

            return res;
        }

};

int main()
{
    vector<int > a;
    a.push_back(4);
    a.push_back(8);
    a.push_back(7);
    a.push_back(9);
    a.push_back(6);

    printVector(a);

    Solution sl;
    int res = sl.maxProfit(a);
    cout << res << endl;

    return 0;
}

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
            vector<int> maxPrice;
            maxPrice.resize(prices.size(), 0);
            int res = 0;

            if(prices.size() == 0)
                return res;

            maxPrice[prices.size() -1] = prices[prices.size() -1];
            for(int i = prices.size() -2; i>= 0; i--)
            {
                if(prices[i] > maxPrice[i+1])
                    maxPrice[i] = prices[i];
                else
                    maxPrice[i] = maxPrice[i+1];
            }

            printVector(maxPrice );

            for(int i = 0; i < prices.size() -1; i++)
            {
                res = max(res,  maxPrice[i+1] - prices[i]);
            }
            return res;
        }

        int maxProfit2(vector<int> &prices) 
        {
            int res = 0;

            if(prices.size() == 0)
                return res;

            int maxPrice = prices[prices.size() -1];

            for(int i = prices.size() - 2; i>=0; i--)
            {
                res =  max(res, maxPrice - prices[i]);
                maxPrice = max(maxPrice, prices[i+1]);
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
    int res = sl.maxProfit2(a);
    cout << res << endl;

    return 0;
}

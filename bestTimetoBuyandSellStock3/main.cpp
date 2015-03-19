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
        int maxProfit(vector<int> &prices) {
            if (prices.size() == 0)
                return 0;

            vector<int> f1(prices.size());
            vector<int> f2(prices.size());

            vector<int> minX(prices.size());
            vector<int> maxX(prices.size());

            minX[0] = prices[0];
            for(int i = 1; i< prices.size();i++ )
            {
                minX[i] = min(minX[i-1], prices[i]);
            }

            maxX[prices.size()-1] = prices[prices.size()-1];
            for(int i = prices.size() -2; i >=0; i-- )
            {
                maxX[i] = max(maxX[i+1], prices[i]);
            }
        
            f1[0] = 0;
            for(int i = 1; i< prices.size();i++ )
            {
                f1[i] = max(f1[i-1],prices[i]-minX[i]);
            }

            f2[prices.size()-1] = 0;
            for(int i = prices.size() -2; i >=0; i-- )
            {
                f2[i] = max(f2[i+1],maxX[i]- prices[i]);
            }

            printVector(f1);
            printVector(f2);

            int sum = 0;

            for(int i = 1; i< prices.size();i++ )
                sum = max(sum, f1[i] + f2[i]);

            return sum;

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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

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

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}


class Solution {
    public:
        int sqrt(int x) {
            int low = 0;
            int high = x;
            int mid = 0;;

            if(x == 0) return 0;
            if(x < 0) return -1;
            if(x == 1) return 1;

            while(low <= high)
            {
                mid = (high - low)/2 + low;
                #if 0
                cout << "low\t" << low << endl;
                cout << "high\t" << high<< endl;
                cout << "mid\t" << mid<< endl;
                #endif
                if( mid  <= x/mid && (mid+1) > x/(mid+1))
                    return mid;
                else if( mid < x/mid )
                {
                   low = mid + 1; 
                }
                else
                {
                   high = mid - 1; 
                }
            }

            return -1;
        }
#if 0
        int sqrt(int x) {
            int low = 0;
            int high = x;
            int mid = 0;;

            while(low <= high)
            {
                mid = (high - low)/2 + low;
                cout << "low\t" << low << endl;
                cout << "high\t" << high<< endl;
                cout << "mid\t" << mid<< endl;
                if(x == INT_MAX)
                    break;
                if( (mid * mid) <= x && (mid+1) * (mid+1) > x)
                    return mid;
                else if(mid * mid < x )
                {
                   low = mid + 1; 
                }
                else
                {
                   high = mid - 1; 
                }
            }

            return mid;
        }
#endif
};

int main()
{


    Solution sl;
#if 1
    cout << sl.sqrt( 0) << endl;
    cout << sl.sqrt( 1) << endl;
    cout << sl.sqrt( 2) << endl;
    cout << sl.sqrt( 3) << endl;
    cout << sl.sqrt( 4) << endl;
    cout << sl.sqrt( 5) << endl;
    cout << sl.sqrt( 8) << endl;
    cout << sl.sqrt( 16) << endl;
#endif
    cout << sl.sqrt( INT_MAX) << endl;

    return 0;
}

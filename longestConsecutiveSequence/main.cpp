#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
        set<int> flag;
        int findBound(int n , bool asc){
            int ans = 0;
            set<int>::iterator iter;
            while((iter = flag.find(n)) != flag.end()){
                flag.erase(iter);
                ans ++;
                if(asc) 
                    n-- ;
                else 
                    n++;
            }
            return ans;
        }
        int longestConsecutive(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            int ans = 0;
            flag.clear();
            for(int i = 0 ; i < num.size() ; i++)
                flag.insert(num[i]);
            for(int i = 0 ; i < num.size(); i++){
                ans = max(findBound(num[i],true) + findBound(num[i]+1,false) , ans); 
            }
            return ans;
        }
};


int main()
{
    vector<int> in;

    in.push_back(100);
    in.push_back(4);
    in.push_back(200);
    in.push_back(1);
    in.push_back(3);
    in.push_back(2);


    Solution sl;
    cout << sl.longestConsecutive(in) << endl;

    return 0;
}

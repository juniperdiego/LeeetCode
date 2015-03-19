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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 #if 0
 Given a collection of intervals, merge all overlapping intervals.

 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 #endif

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i, Interval j)
{
    return i.start < j.start;
}

class Solution {
    public:

        vector<Interval> merge(vector<Interval> &intervals)
        {
            size_t n = intervals.size();
            vector<bool> valid(n, true);
            vector<Interval> res;

            sort(intervals.begin(), intervals.end(), cmp);

#if 0
            for(int i = 0; i < intervals.size(); i++)
            {
                cout << "[" << intervals[i].start << "," << intervals[i].end << "]\t" ;
            }
            cout << endl;
#endif


            for(int i = 1; i < n; i++)
            {
                Interval & pre = intervals[i-1];
                Interval & cur = intervals[i];

                if(pre.end >= cur.start)
                {
                    valid[i-1] = false;

                    cur.start = pre.start;
                    if(pre.end > cur.end)
                        cur.end = pre.end;
                }
            }

            for(int i = 0; i < n; i++)
            {
//                cout << valid[i] << endl;
                if(valid[i] == true)
                    res.push_back(intervals[i]);
            }
            
            return res;
        }
};

int main()
{
    vector<Interval> in;
    vector<Interval> out;

    in.push_back(Interval(1,3));
    in.push_back(Interval(2,6));
    in.push_back(Interval(8,10));
    in.push_back(Interval(15,18));

    Solution sl;
    out = sl.merge(in);

    for(int i = 0; i < out.size(); i++)
    {
        cout << "[" << out[i].start << "," << out[i].end << "]\t" ;
    }
    cout << endl;

    return 0;
}

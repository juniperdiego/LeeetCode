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

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
        {
            size_t n = intervals.size();
            vector<Interval> res;
            Interval merge;

            if(n == 0)
            {
                res.push_back(newInterval);
                return res;
            }
#if 0
            for(int i = 0; i < intervals.size(); i++)
            {
                cout << "[" << intervals[i].start << "," << intervals[i].end << "]\t" ;
            }
            cout << endl;
#endif
            int left = 0, right = 0, i;
            for(i = 0; i < n; i++)
            {
                if(newInterval.start < intervals[i].start)
                {
                    left = i - 1;
                    break;
                }
            }

            if(i == n) //new should be insert at the last 
            {
                left = n-1;
            }

            if(left == -1 || intervals[left].end < newInterval.start)
            {
                left ++;
                merge.start = newInterval.start;
            }
            else
            {
                merge.start = intervals[left].start;
            }

            right = left;
            for(i = left; i < n; i++)
            {
                if(newInterval.end < intervals[i].start)
                {
                    right = i - 1;
                    break;
                }
            }

            if(i == n) //new should be insert at the last 
            {
                right = n-1;
            }

            if(right == -1 || intervals[right].end < newInterval.end)
            {
                merge.end = newInterval.end;
            }
            else
            {
                merge.end = intervals[right].end;
            }

            //cout << "left \t" << left << endl;
            //cout << "right\t" << right << endl;

            for(i = 0; i < left; i++)
            {
                res.push_back(intervals[i]);    
            }

            res.push_back(merge);    

            for(i = right+1; i < n; i++)
            {
                res.push_back(intervals[i]);    
            }
            
            return res;
        }
};

int main()
{
#if 0
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
#endif

    vector<Interval> in;
    vector<Interval> out;
    Solution sl;

#if 0
    in.push_back(Interval(1,3));
    in.push_back(Interval(6,9));
    out = sl.insert(in, Interval(2, 5));

    for(int i = 0; i < out.size(); i++)
    {
        cout << "[" << out[i].start << "," << out[i].end << "]\t" ;
    }
    cout << endl;
#endif

#if 0
    in.clear();
    out = sl.insert(in, Interval(5, 7));

    for(int i = 0; i < out.size(); i++)
    {
        cout << "[" << out[i].start << "," << out[i].end << "]\t" ;
    }
    cout << endl;
#endif

#if 1
    in.clear();
    //in.push_back(Interval(1,2));
    in.push_back(Interval(3,5));
    in.push_back(Interval(6,7));
    in.push_back(Interval(8,10));
    in.push_back(Interval(15,16));
    out = sl.insert(in, Interval(10, 20));

    for(int i = 0; i < out.size(); i++)
    {
        cout << "[" << out[i].start << "," << out[i].end << "]\t" ;
    }
    cout << endl;
#endif

    return 0;
}

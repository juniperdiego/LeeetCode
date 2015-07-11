#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>
#include <limits.h>

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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* root)
{
    while(root)
    {
        cout << root->val<< "\t" ;
        root = root->next;
    }
    cout << "NULL" ;
    cout << endl;
}


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    public:
        int maxPoints(vector<Point>& points) {

            if(points.size() == 0)
                return 0;
            if(points.size() == 1)
                return 1;
            if(points.size() == 2)
                return 2;

            int size = points.size();
            map<double, int> hash;
            int duplicateCnt = 0;
            int rtn = 0;

            for(int i = 0; i < size; i++)
            {
                hash.clear();
                duplicateCnt = 0;
                //calc the max number for each point
                for(int j = i + 1; j < size; j++)
                {
                    if(points[i].x == points[j].x)
                    {
                        if(points[i].y == points[j].y)
                            duplicateCnt++;
                        else
                            hash[double(INT_MAX)]++;
                    }
                    else
                    {
                        double k = ((double)(points[j].y-points[i].y))/(points[j].x-points[i].x);
                        hash[k]++;
                    }
                }
                cout << "dup\t" << duplicateCnt << endl;
                cout << "hash size\t" << hash.size() << endl;

                if(duplicateCnt >rtn )// incase the hash is empty
                    rtn = duplicateCnt;

                for(map<double,int>::iterator it = hash.begin(); it != hash.end(); it++)
                {
                    cout << "here" << endl;
                    if(it->second + duplicateCnt > rtn)
                        rtn = it->second + duplicateCnt;
                }
                cout << "rtn\t" << rtn<< endl;
            }
            return rtn + 1;//remember + 1, including the orginal point
            
        }
};

int main()
{
    vector<Point> vec;
    vec.push_back(Point(0,0));
    vec.push_back(Point(0,0));
    vec.push_back(Point(0,0));

    Solution sl;

    cout << sl.maxPoints(vec) << endl;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
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
    int ladderLength(string start, string end, set<string> &dict) 
    {
        if(start.empty() || end.empty() )
            return 0;
        if(start.size() != end.size())
            return 0;
        if(start.compare(end) == 0)
            return 1;

        size_t size =  start.size();

        queue<string> cur, next;
        cur.push(start);

        int length = 2;

        while(!cur.empty())
        {
            string org = cur.front();
            cur.pop();

            for(int i = 0; i< size; i++)
            {
                string tmp = org;
                for(char j = 'a'; j <= 'z'; j++ )
                {
                    if(tmp[i] == j)
                        continue;
                        //cout << "tmp = " << tmp << endl;
                    if(tmp.compare(end) == 0)
                        return length ;
                    tmp[i] = j;
                    if(dict.find(tmp) != dict.end())
                    {
                        //cout << "push queue " << tmp << endl;
                        next.push(tmp);
                        dict.erase(dict.find(tmp));
                    }
                }
            }
            if(cur.empty() && !next.empty())
            {
                swap(cur, next);
                length ++ ;
            }
        }
        return 0;
    }
};

int main()
{
    string start = "hit";
    string end = "cog";
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");


    Solution sl;
    cout <<endl;
    int l = sl.ladderLength(start, end, dict); 
    
    cout << "l = "<< "\t" << l <<endl;

    return 0;
}


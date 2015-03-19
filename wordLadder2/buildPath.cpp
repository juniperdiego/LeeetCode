// the genPath() funciton is part of Word Ladder problem
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void genPath(string start, string end, vector<string>& path, map<string, vector<string> >map, vector<vector<string> >& result)
{
    path.push_back(end);
    if(start == end)
    {
        result.push_back(path);
    }
    else
    {
        int size = map[end].size();
        for( int i = 0; i < size; i++)
        {
            string str = map[end][i];
            genPath(start, str, path, map, result);
        }
    }
    path.pop_back();
}

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

    vector<string> path;
    map<string, vector<string> >map;
    vector<vector<string> > result;

    vector<string> v;

    v.push_back("dog");
    v.push_back("log");
    v.push_back("com");
    v.push_back("con");
    map["cog"] = v;

    v.clear();
    v.push_back("dot");
    map["dog"] = v;

    v.clear();
    v.push_back("lot");
    map["log"] = v;

    v.clear();
    v.push_back("hot");
    map["dot"] = v;

    v.clear();
    v.push_back("hot");
    map["lot"] = v;

    v.clear();
    v.push_back("hit");
    map["hot"] = v;
#if 0
    v.clear();
    v.push_back("cot");
    map["com"] = v;
    
    v.clear();
    v.push_back("cot");
    map["con"] = v;

    v.clear();
    v.push_back("hot");
    map["cot"] = v;
#endif

    genPath(start, end, path, map, result);
    
    for(int i = 0; i< result.size(); i ++)
    {
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] <<"\t";
            cout <<endl;
    }

    return 0;
}


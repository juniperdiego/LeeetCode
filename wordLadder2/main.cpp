#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
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

void printVector(vector<string> & array )
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
    vector<vector<string> > findLadders(string start, string end, set<string>& dict) 
    {
        vector<vector<string> > result;

        if(start.empty() || end.empty() )
            return result;
        if(start.size() != end.size())
            return result;

        size_t size =  start.size();

        set<string> cur, next;//use set to aviod add duplicate element
        map<string, vector<string> > father;

        cur.insert(start);

        bool found = false;

        while(!cur.empty() && !found)
        {
            for(set<string>::iterator it = cur.begin(); it != cur.end(); it++)
            {
               string curStr= *it; 

               //cout << "=========" <<curStr <<"========================" <<endl;
               for(int i = 0; i< size; i++)
               {
                   for(char j = 'a'; j <= 'z'; j++ )
                   {
                       string nextStr = curStr;
                       if(nextStr[i] == j)
                           continue;
                       nextStr[i] = j;
                       if(nextStr.compare(end) == 0)
                       {
                           //if found, just traverse this layer, not go to next layer
                           found = true;
                           father[nextStr].push_back(curStr);
                       }

#if 0
                       cout << "nextStr = " << nextStr<< endl;
                       cout << "nextStr [i] = " << nextStr[i]<< endl;
                       cout << "i       = " << i<< endl;
                       cout << "j       = " << j<< endl;
#endif
                       if(dict.find(nextStr) != dict.end() && cur.find(nextStr) == cur.end())
                           // must add "&& cur.find(nextStr) == cur.end()"
                           // to avoid the same level 's elemnt point each other
                           // for example hot --> dot
                           //             hot --> lot
                           // but when you travel to dot, may happen dot --> lot
                           // but when you travel to lot, may happen lot --> dot
                           // so when add it to next, we must confirm that lot is not in this level
                       {
                           //cout << "insert\t" << nextStr<< "\tto next queue" << endl;
                           next.insert(nextStr);
                           father[nextStr].push_back(curStr);
                       }
                   }
               }
            }
            
            // remove the cur layer's elements  form dict
            for(set<string>::iterator it = cur.begin(); it != cur.end(); it++)
            {
               string tmp = *it; 
                if(dict.find(tmp) != dict.end())
                {
                    dict.erase(dict.find(tmp));
                    //cout << "erase \t" << tmp <<endl;
                }
            }

            cur.clear();
            swap(cur, next);
        }

        vector<string> path;
        for(map<string, vector<string> >::iterator it = father.begin(); it != father.end(); it++)
        {
            string str =(*it).first; 
            vector<string> vect =(*it).second; 
            //cout << "map key :" << str <<endl;
            for(int i = 0; i < vect.size(); i++)
            {
                //cout << "\tmap value:" << vect[i]<<endl;
            }
        }
        genPath(start, end, path, father, result);
        return result;
    }

    void genPath(string start, string end, vector<string>& path, map<string, vector<string> >map, vector<vector<string> >& result)
    {
        path.push_back(end);
        if(start == end)
        {
            reverse(path.begin(), path.end());
            result.push_back(path);
            //printVector(path);
            reverse(path.begin(), path.end());
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

    vector<vector<string> > result;
    Solution sl;
    result= sl.findLadders(start, end, dict); 

    for(int i = 0; i< result.size(); i ++)
    {
        for(int j = 0; j < result[i].size(); j++)
//            cout << result[i][j] <<"\t";
            cout <<endl;
    }
    return 0;
}


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
        string delRedundantSlash(string in)
        {
            if(in.size() <= 1)
                return in;
            string out;
            out += in[0];
            for(int i = 1; i < in.size(); i++)
            {
                if(in[i] == '/' && in[i-1] == '/')
                    continue;
                out += in[i];
            }

#if 0
            // delete the last '/' if '/' exist at the end
            if( out.size() >= 2
                    && out[out.size() - 1] == '/' 
                    && out[out.size() -2 != '/'] )
            {
                out.erase(out.size()-1, 1);
            }
#endif

            return out;
        }

        string simplifyPath(string path) 
        {
            bool isRoot = false;
            
            path = delRedundantSlash(path); 

            if(path.size() <= 1)
                return path;

            // add the '/' at the end of path
            // inorder or handle this more convenient 
            if(path[path.size()-1] != '/')
                path += '/';

            vector<string> st;
            string res;

            size_t pos = path.find('/') ;
            string tmpStr;
            while(pos != string::npos)
            {
                //cout << "path\t" << path << endl;
                //cout << "pos\t" << pos << endl;
                if(pos != 0)
                {
                    tmpStr = path.substr(0, pos);
                    if(tmpStr.size() == 1 && tmpStr == ".")
                        ;// do nothing
                    else if(tmpStr.size() == 2 && tmpStr == "..")
                    {
                        if(!st.empty())
                            st.pop_back();
                    }
                    else
                        st.push_back(tmpStr);
                }
                path = path.substr(pos+1);  
                pos = path.find('/') ;
            }


            for(int i = 0; i < st.size(); i++)
                res += '/' + st[i];

            if(res.empty())
                res = "/";

            return res;
        }
};

#if 0
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
#endif
int main()
{


    Solution sl;
    cout << sl.simplifyPath("/home//foo/") << endl;
    cout << sl.simplifyPath("/home/") << endl;
    cout << sl.simplifyPath("/") << endl;
    cout << sl.simplifyPath("/../") << endl;
    cout << sl.simplifyPath("/a/./b/../../c/") << endl;


    return 0;
}

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
        cout << array[i]<< "\t";
    cout << endl;
}

void printVector(vector<string> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< endl ;
    cout << endl;
}

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L)
        {

            words.push_back(string(L, 'a'));
            size_t n = words.size();
            int len = 0;
            bool isFirst = true;
            vector<string> res;
            int start = 0, end = 0;
            int remainder = 0;
            string str;
                
            
            for(int i = 0; i < n; i++)
            {
                if(isFirst)
                {
                    isFirst = false;
                    len = words[i].size();
                    start = i;
                    //cout << "start\t" << start << endl;
                }
                else
                {
                    if(words[i].size() + 1 + len <= L) 
                        len += words[i].size() + 1;
                    else
                    {
                        end = i - 1;
                        remainder = L - len;
                        if(start == end) // only one world
                        {
                            str = words[start];
                            for(int j = 0; j < remainder; j++)
                                str += ' ';

                            res.push_back(str);
                            isFirst = true;
                            str.clear();
                            len = 0;

                            i--; //handle from the start begin;
                            continue;
                        }

                        cout << "start\t" << start << endl;
                        cout << "end\t" << end << endl;
                        cout << "n\t" << n<< endl;

                        if(end == n-2) // the last line
                        {
                            for(int j = start; j <= end; j++)
                            {
                                if(j == start)
                                    str += words[j];
                                else
                                    str += ' ' + words[j];
                            }
                            for(int j = 0; j < remainder; j++)
                                str += ' ';
                            
                        }
                        else
                        {
                            int average = remainder/(end - start );
                            remainder = remainder%(end - start );
                            for(int j = start; j <= end; j++)
                            {
                                if(j == start)
                                    str += words[j];
                                else
                                {
                                    int tmp = average;
                                    while(tmp > 0)
                                    {
                                        str += ' ';
                                        tmp--;
                                    }
                                    if(remainder > 0)
                                    {
                                        str += ' ';
                                        remainder --;
                                    }
                                    str += ' ';
                                    str += words[j];
                                }
                            }
                        }
                        
                        //cout << "str:" << str<< endl;
                        res.push_back(str);
                        isFirst = true;
                        str.clear();
                        len = 0;

                        i--; //handle from the start begin;
                    }
                }
                //cout << "len\t" << len<< endl;
                
            }
        
            return res;

        }
};

#if 0
For example,
    words: ["This", "is", "an", "example", "of", "text", "justification."]
    L: 16.

    Return the formatted lines as:
    [
    "This    is    an",
    "example  of text",
    "justification.  "
    ]
#endif

int main()
{

    Solution sl;
    vector<string> in;
    in.push_back("This");
    in.push_back("is");
    in.push_back("an");
    in.push_back("example");
    in.push_back("of");
    in.push_back("text");
    in.push_back("justification");

    vector<string> out;
//    out = sl. fullJustify(in, 16);
    printVector(out);

    in.clear();
    in.push_back("What");
    in.push_back("must");
    in.push_back("be");
    in.push_back("shall");
    in.push_back("be.");
    out = sl. fullJustify(in, 12);
    printVector(out);

    return 0;
}

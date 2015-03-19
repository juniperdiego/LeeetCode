#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>

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

//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
class Solution {
    public:
        string convert(string s, int nRows) {

            if(nRows == 1)
                return s;
            vector<string> strs;
            strs.resize(nRows);
            string result;

            int idx = 0;
            bool upOrDown = false;// false--down, true--up

            for(size_t i = 0; i< s.size(); i++)
            {
                strs[idx] += s[i];
                if(upOrDown == false)
                {
                    if(idx == (nRows-1))
                    {
                        upOrDown = true;
                        idx--;
                    }
                    else
                    {
                        idx++;
                    }
                }
                else
                {
                    if(idx == 0)
                    {
                        upOrDown = false;
                        idx++;
                    }
                    else
                    {
                        idx--;
                    }
                }
            }
            for(size_t i = 0; i< strs.size(); i++)
            {
                result += strs[i];
            }
            
            return result;
        }
};



int main()
{
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    string str = "PAYPALISHIRING";
    Solution sl;
    cout << sl.convert(str, 3) << endl;;

    str = "AB";
    cout << sl.convert(str, 1) << endl;;

}

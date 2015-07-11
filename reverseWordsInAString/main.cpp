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
    private:
        void reverseWord(string &s, int left, int right)
        {
            char tmp;
            while(left < right)
            {
                tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
    public:
        void reverseWords(string &s) {
            if(s.size() == 0)
                return;

            //reverse all words
            reverseWord(s, 0, s.size() - 1);
            
            s.push_back(' ');//inorder to handler the latest part
            int size = s.size(); 

            int writePos = 0;//position which will be written
            
            int left = 0, right = 0;
            for(int i = 0; i < size; i++)
            {
                //convert multiple spaces to one space
                if(s[i] != ' ')
                {
                    if(i == 0 || s[i-1] == ' ')
                    {
                        left = i;
                        right = i;
                    }
                    else
                        right ++;
                }
                else //if (s[i] == ' ')
                {
                    if(i > 0 && s[i-1] != ' ')
                    {
                        //cout << "left\t" << left << endl;
                        //cout << "right\t" << right<< endl;
                        reverseWord(s, left, right);

                        //move the part to writePos
                        // it means memmove
                        while(left <= right)
                        {
                            s[writePos++] = s[left++];
                        }
                        s[writePos++] = ' ';//add space after the word
                    }
                }
            }

            if( writePos > 0) //remove the latest space
                s.resize(writePos - 1);
            else
                s.resize(0);//the str only contains space
        }
};

int main()
{

    string str;
    Solution sl;

    str = "the sky is blue";
    //sl.reverseWords(str);
    cout << str << endl;

    str = " ";
    sl.reverseWords(str);
    cout << "[" <<str <<"]" << endl;

    return 0;
}

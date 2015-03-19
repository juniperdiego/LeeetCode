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
        int minDistance(string word1, string word2)
        { 
            size_t size1 = word1.size();
            size_t size2 = word2.size();

            vector <vector<int> >f;
            vector<int> a;
            a.resize(size2+1, 0);
            for(int i = 0; i< size1+1; i++)
            {
                f.push_back(a);
            }

            for(int i = 0; i<= size1; i++)
                f[i][0] = i;
            for(int i = 0; i<= size2; i++)
                f[0][i] = i;

            for(int i = 0; i< size1; i++)
            {
                for(int j = 0; j< size2; j++)
                {

                    int min1 = f[i][j+1];
                    min1 = min(min1, f[i+1][j]) + 1;
                    int min2 = f[i][j];
                    if(word1[i] != word2[j])
                        min2++;
                    f[i+1][j+1]= min(min1, min2);
                }
            }
            
            return f[size1][ size2];
        }
};


int main()
{
    string s1("abcd");
    string s2("cdef");
    Solution sl;
    cout << sl.minDistance( s1, s2);
    cout <<endl<< "==============" <<endl;

    cout << endl;
    return 0;
}

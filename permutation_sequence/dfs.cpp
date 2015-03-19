#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void printVector(vector<int> array );

int dfs(vector<int>& array, int t)
{
    size_t size =  array.size();
    if(t == size)
        printVector(array);

    //dfs to the next level
    for(int i = t; i < size; i++)
    {
        int j = i;
        string s;
        while(j --)
            s += "\t" ;
       //cout <<s << "================   start   ==================================;; i =" <<i << endl;
       swap(array[t],array[i]); 
       //cout <<s << "begin to swap " << array[i]<< " and " << array[t] <<endl; ;
       //cout <<s << "call dfs -- lvevel " << t+1 <<endl;
       dfs(array, t+1);
       //cout <<s << "return dfs -- lvevel " << t+1 <<endl;
       //cout <<s << "end  to swap" << array[i]<< " and " << array[t] <<endl; ;
       swap(array[i],array[t]); 
       //cout <<s << "================= end     ==================================;; i =" <<i << endl;
    }

}


void printVector(vector<int> array )
{
    for(int i = 0; i <array.size(); i++)
        cout << array[i]<< "\t" ;
    cout << endl;
}

int main()
{
    vector<int> b ;
#if 1
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
#else
    b.push_back(4);
    b.push_back(3);
    b.push_back(2);
    b.push_back(1);
    b.push_back(0);
#endif

    sort(b.begin(), b.end());
    dfs(b, 0);

    return 0;
}

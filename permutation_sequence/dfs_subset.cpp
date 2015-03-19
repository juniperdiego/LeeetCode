#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void printVector(vector<int> array );

void dfs(vector<int>& array, int dep)
{
    int size =  array.size();
    if(dep == size)
    {
        printVector(array);
        return;
    }
    //dfs to the next level
    for(int i = 0; i < 2; i++)
    {
        array[dep] = i;
        dfs(array, dep+1);
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
    b.resize(5, 0);
    dfs(b, 0);

    return 0;
}

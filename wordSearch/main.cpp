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

#if 0
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
    Given board =

    [
    ["ABCE"],
    ["SFCS"],
    ["ADEE"]
    ]
    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.
#endif


class Solution {
        vector<vector<bool> > canUse;
    public:
        bool dfs(int dep, int x, int y, vector<vector<char> >& board, string& word)
        {
            if(dep == word.size())
                return true;

            int row = board.size();
            int col = board[0].size();
            if(x < 0 || x >= row ||
                y <0 || y >= col )
                return false;

            if(canUse[x][y] == false)
                return false;

            if(board[x][y] != word[dep])
                return false;

            //mark
            canUse[x][y] = false;

            bool retVal = dfs(dep+1, x+1, y, board, word) ||
                dfs(dep+1, x-1, y, board, word) ||
                dfs(dep+1, x, y+1, board, word) ||
                dfs(dep+1, x, y-1, board, word);

            //mark
            canUse[x][y] = true;
            
            return retVal;
        }

        bool exist(vector<vector<char> > &board, string word)
        {
            int row = board.size();
            if(row == 0) return false;
            int col = board[0].size();

            canUse.clear();
            vector<bool> tmp(col, true);
            canUse.resize(row, tmp);

            for(int i = 0; i< row; i++)
            {
                for(int j = 0; j< col; j++)
                {
                    if(dfs(0, i, j, board, word ))         
                        return true;
                }
            }
            return false;
        }
};


int main()
{
#if 0
    ["ABCE"],
    ["SFCS"],
    ["ADEE"]
    ]
    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.
#endif

    vector<char> tmp;
    vector<vector<char> > board;

    tmp.push_back('b');
    tmp.push_back('b');
    board.push_back(tmp);

    tmp.clear();
    tmp.push_back('a');
    tmp.push_back('b');
    board.push_back(tmp);

    tmp.clear();
    tmp.push_back('b');
    tmp.push_back('a');
    board.push_back(tmp);

    Solution sl;
    cout << sl.exist(board, "a") << endl;

#if 0
    tmp.push_back('A');
    tmp.push_back('B');
    tmp.push_back('C');
    tmp.push_back('D');
    board.push_back(tmp);

    tmp.clear();
    tmp.push_back('S');
    tmp.push_back('F');
    tmp.push_back('C');
    tmp.push_back('S');
    board.push_back(tmp);

    tmp.clear();
    tmp.push_back('A');
    tmp.push_back('D');
    tmp.push_back('E');
    tmp.push_back('E');
    board.push_back(tmp);

    Solution sl;
    cout << sl.exist(board, "ASADEE") << endl;
    cout << sl.exist(board, "ABCCED") << endl;
    cout << sl.exist(board, "SEE") << endl;
    cout << sl.exist(board, "ABCB") << endl;
#endif

    return 0;
}

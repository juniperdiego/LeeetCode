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
            queue<pair<int, int> > m_que;
    public:
        void dfs(vector<vector<int> > &board, int i, int j)
        {
            size_t row = board.size();
            size_t col = board[0].size();

            if(i < 0 || i > row-1 || j < 0 || j > col-1)
                return;
            if( board[i][j] == INT_MAX)
                return;
                cout << "(" << i <<"," << j << ") = " <<  board[i][j] << endl ;
            board[i][j] = INT_MAX;//tag, in order to reverse back
            dfs(board, i, j-1);
            dfs(board, i, j+1);
            dfs(board, i-1, j);
            dfs(board, i+1, j);
        }

        void fill(vector<vector<int> > &board, int i, int j){
            size_t row = board.size();
            size_t col = board[0].size();

            if(i<0 || i>=row || j<0 || j>=col || board[i][j]== INT_MAX)
                return;

            pair<int, int> p ;
            p.first = i;
            p.second = j;
            m_que.push(p);

            cout << "(" << i <<"," << j << ") = " <<  board[i][j] << endl ;
            board[i][j]= INT_MAX;
             
        }


        void bfs(vector<vector<int> > &board, int i, int j)
        {
            fill(board, i, j);

            while(!m_que.empty())
            {
                pair<int, int> p = m_que.front() ;
                m_que.pop();

                i = p.first;
                j = p.second;

                fill(board, i, j-1);
                fill(board, i, j+1);
                fill(board, i-1, j);
                fill(board, i+1, j);
            }

        }

        void dfs(vector<vector<int> > board) 
        { 
            if (board.empty()) return;

            dfs(board, 2 ,2);

        }
        void bfs(vector<vector<int> > board) 
        { 
            if (board.empty()) return;

            bfs(board, 2 ,2);

        }
};

int main()
{
    vector<vector<int> > board;
    vector<int> a;
    a.resize(4, 0);

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    board.push_back(a);

    a[0] = 4;
    a[1] = 5;
    a[2] = 6;
    a[3] = 7;
    board.push_back(a);

    a[0] = 8;
    a[1] = 9;
    a[2] = 10;
    a[3] = 11;
    board.push_back(a);

    a[0] = 12;
    a[1] = 13;
    a[2] = 14;
    a[3] = 15;
    board.push_back(a);


//    board.clear();
    Solution sl;


    for(int i = 0; i < board.size(); i++)
        printVector(board[i]);

    cout <<endl;
    cout << "dfs" <<endl;
    sl.dfs(board);
    cout << "bfs" <<endl;
    sl.bfs(board);
    
    for(int i = 0; i < board.size(); i++)
        printVector(board[i]);

    return 0;
}


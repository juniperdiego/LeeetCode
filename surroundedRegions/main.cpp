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
        void dfs(vector<vector<char> > &board, int i, int j)
        {
            size_t row = board.size();
            size_t col = board[0].size();

            if(i < 0 || i > row-1 || j < 0 || j > col-1)
                return;
            if(board[i][j] != 'O')
                return;
            board[i][j] = '*';//tag, in order to reverse back
            dfs(board, i, j-1);
            dfs(board, i, j+1);
            dfs(board, i-1, j);
            dfs(board, i+1, j);
        }

        void fill(vector<vector<char> > &board, int x, int y){
            size_t row = board.size();
            size_t col = board[0].size();

            if(x<0 || x>=row || y<0 || y>=col || board[x][y]!='O')
                return;

            pair<int, int> p ;
            p.first = x;
            p.second = y;
            m_que.push(p);

            board[x][y]='&';
        }


        void bfs(vector<vector<char> > &board, int i, int j)
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

        void solve(vector<vector<char> > &board) 
        { 
            if (board.empty()) return;
            size_t row = board.size();
            size_t col = board[0].size();

            // dfs traverse form the up and down
            for(int j = 0; j < col; j++)
            {
                dfs(board, 0 ,j);
                dfs(board,row-1, j);
#if 0
                bfs(board, 0 ,j);
                bfs(board,row-1, j);
#endif
            }

            // dfs traverse form the left and right 
            for(int i = 0; i < row; i++)
            {
                dfs(board, i, 0);
                dfs(board, i, col-1);
#if 0
                bfs(board, i, 0);
                bfs(board, i, col-1);
#endif
            }

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if(board[i][j] == 'O')
                        board[i][j] = 'X';
                    else if(board[i][j] == '*')
                        board[i][j] = 'O';
                }
            }


        }
};

int main()
{
    vector<char> a;
    a.resize(4, 'X');
    vector<vector<char> > board;
    board.push_back(a);
    board.push_back(a);
    board.push_back(a);
    board.push_back(a);

    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';

//    board.clear();
    Solution sl;


    for(int i = 0; i < board.size(); i++)
        printVector(board[i]);

    cout <<endl;
    sl.solve(board);
    
    for(int i = 0; i < board.size(); i++)
        printVector(board[i]);

    return 0;
}


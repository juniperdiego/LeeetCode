#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class Solution {
    public:
        bool m_used[9];
        bool isValidSudoku(const vector<vector<char>>& board) {

            // check the row
            for (int i = 0; i < 9; ++i) {
                fill(m_used, m_used + 9, false);
                for (int j = 0; j < 9; ++j)
                {
                    if (!check(board[i][j]))
                        return false;
                    m_used[board[i][j] - '1'] = true;
                }
            }

            // check the column
            for (int i = 0; i < 9; ++i) {
                fill(m_used, m_used + 9, false);
                for (int j = 0; j < 9; ++j)
                {
                    if (!check(board[j][i]))
                        return false;
                    m_used[board[j][i] - '1'] = true;
                }
            }

            // check the 3x3 box
            for (int r = 0; r < 3; ++r) 
                for( int c = 0; c < 3; ++c) 
                {
                    fill(m_used, m_used + 9, false);
                    for (int i = r * 3; i < r * 3 + 3; ++i)
                        for (int j = c * 3; j < c * 3 + 3; ++j)
                        {
                            if (!check(board[i][j]))
                                return false;
                            m_used[board[i][j] - '1'] = true;
                        }
                }
        return true;
        }
        bool check(char ch) {
            if (ch == '.') return true;
            if (m_used[ch - '1'] == true)
                return false;
            else
                return true;
        }
};

int main()
{
    return 0;
}

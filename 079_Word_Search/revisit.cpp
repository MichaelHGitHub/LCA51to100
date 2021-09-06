#include "header.h"

static bool search(vector<vector<char>>& board, vector<vector<bool>>& marks, int row, int col, string& word, int pos);

bool exist_r(vector<vector<char>>& board, string word)
{
    vector<vector<bool>> marks(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (search(board, marks, i, j, word, 0))
            {
                return true;
            }
        }
    }

    return false;
}

bool search(vector<vector<char>>& board, vector<vector<bool>>& marks, int row, int col, string& word, int pos)
{
    if (pos >= word.length())
    {
        return true;
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size())
    {
        return false;
    }

    if (marks[row][col])
    {
        return false;
    }

    if (board[row][col] != word[pos])
    {
        return false;
    }

    marks[row][col] = true;

    bool result = 
        search(board, marks, row + 1, col, word, pos + 1) ||
        search(board, marks, row, col + 1, word, pos + 1) ||
        search(board, marks, row - 1, col, word, pos + 1) ||
        search(board, marks, row , col - 1, word, pos + 1);

    marks[row][col] = false;

    return result;
}
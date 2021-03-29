#include "header.h"

static bool search(vector<vector<char>>& board, string& word, int index, int row, int col);

// Start from each of the element in the 2D array, moving up/down/left/right
// to search the word, mark the visited letters so that we don't get
// repeating letters. No extra space is needed for the visited mark, ust mark
// the cell of the board, it will be refilled back to its original value
// at upper level call.
bool exist2(vector<vector<char>>& board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (search(board, word, 0, i, j))
            {
                return true;
            }
        }
    }

    return false;
}

bool search(vector<vector<char>>& board, string& word, int index, int row, int col)
{
    if (index == word.length())
    {
        return true;
    }

    if (row < 0 || col < 0 || row == board.size() || col == board[row].size())
    {
        return false;
    }

    if (board[row][col] == '*')
    {
        return false;
    }

    if (board[row][col] == word[index])
    {
        // Save the letter of the cell and mark it as visited.
        char c = board[row][col];
        board[row][col] = '*';
        if (search(board, word, index + 1, row + 1, col))
        {
            return true;
        }
        if (search(board, word, index + 1, row - 1, col))
        {
            return true;
        }
        if (search(board, word, index + 1, row, col + 1))
        {
            return true;
        }
        if (search(board, word, index + 1, row, col - 1))
        {
            return true;
        }
        // Refill the cell with its original value.
        board[row][col] = c;
    }

    return false;
}
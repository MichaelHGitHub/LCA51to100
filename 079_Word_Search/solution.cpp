#include "header.h"

static bool search(vector<vector<bool>>& visited, vector<vector<char>>& board, string& word, int index, int row, int col);

// Start from each of the element in the 2D array, moving up/down/left/right
// to search the word, mark the visited letters so that we don't get
// repeating letters.
bool exist(vector<vector<char>>& board, string word)
{
    // Allocate another 2D array to save the visited mark
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (search(visited, board, word, 0, i, j))
            {
                return true;
            }
        }
    }

    return false;
}

bool search(vector<vector<bool>>& visited, vector<vector<char>>& board, string& word, int index, int row, int col)
{
    if (index == word.length())
    {
        return true;
    }

    if (row < 0 || col < 0 || row == board.size() || col == board[row].size())
    {
        return false;
    }

    if (visited[row][col])
    {
        return false;
    }

    if (board[row][col] == word[index])
    {
        visited[row][col] = true;
        if (search(visited, board, word, index + 1, row + 1, col))
        {
            return true;
        }
        if (search(visited, board, word, index + 1, row -1, col))
        {
            return true;
        }
        if (search(visited, board, word, index + 1, row, col + 1))
        {
            return true;
        }
        if (search(visited, board, word, index + 1, row, col - 1))
        {
            return true;
        }
        visited[row][col] = false;
    }

    return false;
}
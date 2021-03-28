#include "header.h"

int lengthOfLastWord(string s)
{
    int last_len = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s.pop_back();
        }
        else
        {
            break;
        }
    }

    for (int i = s.length() -1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            ++last_len;
        }
        else
        {
            break;
        }
    }

    return last_len;
}
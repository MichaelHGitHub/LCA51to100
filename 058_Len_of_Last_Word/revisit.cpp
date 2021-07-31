#include "header.h"

int lengthOfLastWord_r(string s)
{
    int last_length = 0;
    int cur_length = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (cur_length != 0)
            {
                last_length = cur_length;
                cur_length = 0;
            }
        }
        else
        {
            ++cur_length;
            if (i == s.length() - 1)
            {
                last_length = cur_length;
            }
        }
    }
    return last_length;
}
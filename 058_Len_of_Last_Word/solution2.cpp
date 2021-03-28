#include "header.h"

// Scan backwards from the end of string, skipping the tailing ' 's.
// count the letters until encounting the first ' ' before the 
// last word.
int lengthOfLastWord2(string s)
{
    int last_len = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        // If counting has started, the ' ' are at the very end.
        if (last_len == 0 && s[i] == ' ')
        {
            continue;
        }
        // Start counting
        else if(s[i] != ' ')
        {
            ++last_len;
        }
        // First ' ' before last word.
        else
        {
            break;
        }
    }

    return last_len;
}
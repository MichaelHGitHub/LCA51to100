#include "header.h"

// Allocating a result string with max(a.length, b.length) + 1. 
// the extra 1 char is for possible carry-on digit.
// Add a and b bit by bit, also take care of the carry-on.
string addBinary(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();
    int len_result = max(len_a, len_b) + 1;

    string result(len_result, '0');

    int carry_on = 0;
    for (int i = len_result - 1; i >= 0; i--)
    {
        int s = 0;

        if (i - (len_result - len_a) >= 0)
        {
            s += a[i - (len_result - len_a)] - '0';
        }

        if (i - (len_result - len_b) >= 0)
        {
            s += b[i - (len_result - len_b)] - '0';
        }

        result[i] = ((s + carry_on) % 2) + '0';
        carry_on = (s + carry_on) / 2;
    }

    if (result[0] == '0')
    {
        return string(result.begin() + 1, result.end());
    }
    else
    {
        return result;
    }
}
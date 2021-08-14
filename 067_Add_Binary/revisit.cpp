#include "header.h"

string addBinary_r(string a, string b)
{
    string result(max(a.length(), b.length()) + 1, '0');
    int carry_on = 0;

    int m = result.length() - a.length();
    int n = result.length() - b.length();

    for (int i = result.length() - 1; i >= 0; i--)
    {
        int sum = carry_on;
        if (i >= m)
        {
            sum += (a[i - m] - '0');
        }
        if (i >= n)
        {
            sum += (b[i - n] - '0');
        }

        result[i] = (sum % 2) + '0';
        carry_on = sum / 2;
    }

    if (result[0] == '1')
    {
        return result;
    }
    else
    {
        return string(result.begin() + 1, result.end());
    }
}
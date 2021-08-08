#include "header.h"

vector<int> plusOne_r(vector<int>& digits)
{
    vector<int> temp(digits.size() + 1, 0);

    int add_on = 1;
    for (int i = temp.size() - 1; i > 0; i--)
    {
        int sum = add_on + digits[i - 1];
        temp[i] = sum % 10;
        add_on = sum / 10;
    }
    temp[0] = add_on;

    if (temp[0])
    {
        return temp;
    }
    else
    {
        return vector<int>(temp.begin() + 1, temp.end());
    }
}
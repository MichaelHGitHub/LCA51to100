#include "header.h"

vector<int> plusOne(vector<int>& digits)
{
    // Allocate one more space to save the possible carry on
    // at the beginning.
    vector<int> temp(digits.size() + 1, 0);

    // Plus one to the last digit
    temp[temp.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
    int carry_on = (digits[digits.size() - 1] + 1) / 10;

    // Fill in other digits
    for (int i = digits.size() - 2; i >= 0; i--)
    {
        temp[i + 1] = (digits[i] + carry_on) % 10;
        carry_on = (digits[i] + carry_on) / 10;
    }

    // Don't forget to last carry on
    if (carry_on != 0)
    {
        temp[0] = carry_on;
    }

    if (temp[0] == 0)
    {
        return vector<int>(temp.begin() + 1, temp.end());
    }
    else
    {
        return temp;
    }
}
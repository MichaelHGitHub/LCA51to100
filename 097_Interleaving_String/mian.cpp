#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_S_S_S_B> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        bool result = isInterleave_r(test_data[i].input, test_data[i].input2, test_data[i].input3);

        CheckResults(test_data[i], result);
    }

    return 0;
}
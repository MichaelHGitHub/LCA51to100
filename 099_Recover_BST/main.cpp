#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_T_T> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        recoverTree(test_data[i].input);

        CheckResults(test_data[i]);
    }

    return 0;
}
#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VI_I_VI_I_VI> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        merge(test_data[i].input, test_data[i].input2, test_data[i].input3, test_data[i].input4);

        CheckResults(test_data[i], test_data[i].input);
    }

    return 0;
}
#include "header.h"


int main(char* args[], int argc)
{
    vector<TD_VVI_VVI> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        setZeroes_r(test_data[i].input);

        CheckResults(test_data[i], test_data[i].input);
    }

    return 0;
}



#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VVI_VI_VVI> test_data = {};

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        vector<vector<int>> result = insert_r(test_data[i].input, test_data[i].input2);

        CheckResults(test_data[i], result);
    }

    return 0;
}




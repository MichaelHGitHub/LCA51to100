#include "header.h"

void PrepareTestData(vector<TD_I_I_VVI>& testData)
{
    TD_I_I_VVI data;

    data.input = 4;
    data.input2 = 2;
    data.output = {
            {2, 4},
            {3, 4},
            {2, 3},
            {1, 2},
            {1, 3},
            {1, 4}
    };
    testData.push_back(data);

    data.input = 1;
    data.input2 = 1;
    data.output = { {1} };
    testData.push_back(data);

}
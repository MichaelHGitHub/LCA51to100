#include "header.h"

void PrepareTestData(vector<TD_I_VVI>& testData)
{
    TD_I_VVI data;

    data.input = 3;
    data.output = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    testData.push_back(data);

    data.input = 1;
    data.output = {{1}};
    testData.push_back(data);

}
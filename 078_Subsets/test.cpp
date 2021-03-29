#include "header.h"

void PrepareTestData(vector<TD_VI_VVI>& testData)
{
    TD_VI_VVI data;

    data.input = {1, 2, 3};
    data.output = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    testData.push_back(data);

    data.input = {0};
    data.output = {{}, {0}};
    testData.push_back(data);
}
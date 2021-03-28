#include "header.h"


void PrepareTestData(vector<TD_VVI_VVI>& testData)
{
    TD_VVI_VVI data;

    data.input = { {1, 4}, {2, 3} };
    data.output = { {1, 4} };
    testData.push_back(data);

    data.input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    data.output = {{1, 6}, {8, 10}, {15, 18}};
    testData.push_back(data);

    data.input = {{1, 4}, {4, 5}};
    data.output = {{1, 5}};
    testData.push_back(data);
}
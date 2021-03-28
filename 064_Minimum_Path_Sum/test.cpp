#include "header.h"

void PrepareTestData(vector<TD_VVI_I>& testData)
{
    TD_VVI_I data;

    data.input = { {1, 3}, {1, 5}};
    data.output = 7;
    testData.push_back(data);

    data.input = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    data.output = 7;
    testData.push_back(data);

    data.input = {{1, 2, 3}, {4, 5, 6}};
    data.output = 12;
    testData.push_back(data);

}
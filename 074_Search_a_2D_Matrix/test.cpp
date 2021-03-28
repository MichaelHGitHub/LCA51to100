#include "header.h"

void PrepareTestData(vector<TD_VVI_I_B>& testData)
{
    TD_VVI_I_B data;

    data.input = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    data.input2 = 3;
    data.output = true;
    testData.push_back(data);

    data.input = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    data.input2 = 13;
    data.output = false;
    testData.push_back(data);

}
#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    data.output = 6;
    testData.push_back(data);

    data.input = { 1, -1, -2 };
    data.output = 1;
    testData.push_back(data);

    data.input = { -2, 1 };
    data.output = 1;
    testData.push_back(data);



    data.input = { 1 };
    data.output = 1;
    testData.push_back(data);

    data.input = { 5,4,-1,7,8 };
    data.output = 23;
    testData.push_back(data);
}
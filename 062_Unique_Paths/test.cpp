#include "header.h"

void PrepareTestData(vector<TD_I_I_I>& testData)
{
    TD_I_I_I data;

    data.input = 23;
    data.input2 = 12;
    data.output = 193536720;
    testData.push_back(data);

    data.input = 2;
    data.input2 = 2;
    data.output = 2;
    testData.push_back(data);

    data.input = 3;
    data.input2 = 7;
    data.output = 28;
    testData.push_back(data);

    data.input = 3;
    data.input2 = 2;
    data.output = 3;
    testData.push_back(data);

    data.input = 7;
    data.input2 = 3;
    data.output = 28;
    testData.push_back(data);

    data.input = 3;
    data.input2 = 3;
    data.output = 6;
    testData.push_back(data);
}
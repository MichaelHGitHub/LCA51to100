#include "header.h"

void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data;

    data.input = "27";
    data.output = 1;
    testData.push_back(data);

    data.input = "12";
    data.output = 2;
    testData.push_back(data);

    data.input = "226";
    data.output = 3;
    testData.push_back(data);

    data.input = "0";
    data.output = 0;
    testData.push_back(data);

    data.input = "06";
    data.output = 0;
    testData.push_back(data);

    data.input = "1201234";
    data.output = 3;
    testData.push_back(data);

    data.input = "111111111111111111111111111111111111111111111";
    data.output = 1836311903;
    testData.push_back(data);
}
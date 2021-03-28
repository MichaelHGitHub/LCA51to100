#include "header.h"

void PrepareTestData(vector<TD_S_I>& testData)
{
    TD_S_I data;

    data.input = "Hello World     ";
    data.output = 5;
    testData.push_back(data);

    data.input = "Hello World";
    data.output = 5;
    testData.push_back(data);

    data.input = " ";
    data.output = 0;
    testData.push_back(data);

}
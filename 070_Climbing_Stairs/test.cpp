#include "header.h"

void PrepareTestData(vector<TD_I_I>& testData)
{
    TD_I_I data;

    data.input = 44;
    data.output = 1134903170;
    testData.push_back(data);

    data.input = 1;
    data.output = 1;
    testData.push_back(data);

    data.input = 2;
    data.output = 2;
    testData.push_back(data);

    data.input = 3;
    data.output = 3;
    testData.push_back(data);

    data.input = 4;
    data.output = 5;
    testData.push_back(data);

}
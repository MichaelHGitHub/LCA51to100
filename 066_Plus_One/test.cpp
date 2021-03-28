#include "header.h"

void PrepareTestData(vector<TD_VI_VI>& testData)
{
    TD_VI_VI data;

    data.input = { 1,2,3 };
    data.output = { 1,2,4 };
    testData.push_back(data);

    data.input = { 4,3,2,1 };
    data.output = { 4,3,2,2 };
    testData.push_back(data);

    data.input = { 0 };
    data.output = { 1 };
    testData.push_back(data);
}
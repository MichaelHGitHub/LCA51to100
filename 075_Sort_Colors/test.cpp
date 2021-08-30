#include "header.h"

void PrepareTestData(vector<TD_VI_VI>& testData)
{
    TD_VI_VI data;

    data.input = { 1,2, 0 };
    data.output = { 0,1,2 };
    testData.push_back(data);

    data.input = { 0,2,1 };
    data.output = { 0,1,2 };
    testData.push_back(data);

    data.input = { 2,0,1 };
    data.output = { 0,1,2 };
    testData.push_back(data);

    data.input = { 2,0,2,1,1,0 };
    data.output = { 0,0,1,1,2,2 };
    testData.push_back(data);

    data.input = {0};
    data.output = { 0 };
    testData.push_back(data);

    data.input = { 1 };
    data.output = { 1 };
    testData.push_back(data);

}
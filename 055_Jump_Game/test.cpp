#include "header.h"

void PrepareTestData(vector<TD_VI_B>& testData)
{
    TD_VI_B data;

    data.input = { 3, 1, 2, 0, 0 };
    data.output = true;
    testData.push_back(data);

    data.input = { 2, 5, 0, 0 };
    data.output = true;
    testData.push_back(data);

    data.input = { 2,0,0 };
    data.output = true;
    testData.push_back(data);

    data.input = { 2,3,1,1,4 };
    data.output = true;
    testData.push_back(data);

    data.input = { 3,2,1,0,4 };
    data.output = false;
    testData.push_back(data);

    data.input = { 0,2,3 };
    data.output = false;
    testData.push_back(data);

}
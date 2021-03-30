#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;


    data.input = { 1, 1, 1};
    data.output = 2;
    testData.push_back(data);

    data.input = { 1, 1, 1, 2, 2, 3 };
    data.output = 5;
    testData.push_back(data);

    data.input = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    data.output = 7;
    testData.push_back(data);

}
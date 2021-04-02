#include "header.h"

void PrepareTestData(vector<TD_I_VI>& testData)
{
    TD_I_VI data;

    data.input = 1;
    data.output = { 0,1 };
    testData.push_back(data);

    data.input = 2;
    data.output = { 0,1,3,2 };
    testData.push_back(data);

    data.input = 5;
    data.output = { 0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8, 24, 25, 27, 26, 30, 31, 29, 28, 20, 21, 23, 22, 18, 19, 17, 16 };
    testData.push_back(data);
}
#include "header.h"

void PrepareTestData(vector<TD_VI_I_VI_I_VI>& testData)
{
    TD_VI_I_VI_I_VI data;

    data.input = { 1,2,3,0,0,0 };
    data.input2 = 3;
    data.input3 = { 2,5,6 };
    data.input4 = 3;
    data.output = { 1,2,2,3,5,6 };
    testData.push_back(data);

    data.input = { 1 };
    data.input2 = 1;
    data.input3 = {  };
    data.input4 = 0;
    data.output = { 1 };
    testData.push_back(data);
}
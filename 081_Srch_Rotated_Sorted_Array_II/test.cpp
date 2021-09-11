#include "header.h"

void PrepareTestData(vector<TD_VI_I_B>& testData)
{
    TD_VI_I_B data;

    data.input = { 1 };
    data.input2 = 1;
    data.output = true;
    testData.push_back(data);

    data.input = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    data.input2 = 2;
    data.output = true;
    testData.push_back(data);

    data.input = { 15,16,19,20,25,1,3,4,5,7,10,14 };
    data.input2 = 25;
    data.output = true;
    testData.push_back(data);

    data.input = { 5, 1, 3 };
    data.input2 = 5;
    data.output = true;
    testData.push_back(data);

    data.input = { 1, 1 };
    data.input2 = 1;
    data.output = true;
    testData.push_back(data);

    data.input = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    data.input2 = 13;
    data.output = true;
    testData.push_back(data);

    data.input = { 1, 0, 1, 1, 1 };
    data.input2 = 0;
    data.output = true;
    testData.push_back(data);

    data.input = { 2,5,6,0,1};
    data.input2 = 0;
    data.output = true;
    testData.push_back(data);

    data.input = { 2,5,6,0,0,1,2 };
    data.input2 = 0;
    data.output = true;
    testData.push_back(data);

    data.input = { 2,5,6,0,0,1,2 };
    data.input2 = 3;
    data.output = false;
    testData.push_back(data);

}
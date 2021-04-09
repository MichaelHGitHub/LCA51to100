#include "header.h"

void PrepareTestData(vector<TD_T_B>& testData)
{
    TD_T_B data;

    data.input = GenerateTree({ 10, 5, 15, NULL, NULL, 6, 20 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 1, 1 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 2,1,3 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 5,1,4,NULL,NULL,3,6 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 5, 4, 6, NULL, NULL, 3, 7 });
    data.output = false;
    testData.push_back(data);
}
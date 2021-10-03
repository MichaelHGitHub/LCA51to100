#include "header.h"

void PrepareTestData(vector<TD_T_T_B>& testData)
{
    TD_T_T_B data;

    data.input = GenerateTree({ 10,5,15 });
    data.input2 = GenerateTree({ 10,5,NULL_NODE_VALUE,NULL_NODE_VALUE,15 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,3 });
    data.input2 = GenerateTree({ 1,2,3 });
    data.output = true;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2 });
    data.input2 = GenerateTree({ 1,NULL_NODE_VALUE,2 });
    data.output = false;
    testData.push_back(data);

    data.input = GenerateTree({ 1,2,1 });
    data.input2 = GenerateTree({ 1,1,2 });
    data.output = false;
    testData.push_back(data);


}
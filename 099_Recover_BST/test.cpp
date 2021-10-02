#include "header.h"

void PrepareTestData(vector<TD_T_T>& testData)
{
    TD_T_T data;

    data.input = GenerateTree({ 1,3, NULL_NODE_VALUE, NULL_NODE_VALUE,2 });
    data.output = GenerateTree({ 3, 1, NULL_NODE_VALUE, NULL_NODE_VALUE, 2 });
    testData.push_back(data);

    data.input = GenerateTree({ 3,1,4,NULL_NODE_VALUE,NULL_NODE_VALUE,2 });
    data.output = GenerateTree({ 2,1,4,NULL_NODE_VALUE,NULL_NODE_VALUE,3 });
    testData.push_back(data);
}
#include "header.h"

void PrepareTestData(vector<TD_VI_VVI>& testData)
{
    TD_VI_VVI data;

    data.input = { 4, 4, 4, 1, 4 };
    data.output = {{}, {1}, {1, 4}, {1, 4, 4}, {1, 4, 4, 4}, {1, 4, 4, 4, 4}, {4}, {4, 4}, {4, 4, 4}, {4, 4, 4, 4}};
    testData.push_back(data);

    data.input = { 1,2,2 };
    data.output = { {} ,{1},{1,2},{1,2,2},{2},{2,2} };
    testData.push_back(data);

    data.input = { 0 };
    data.output = { {} ,{0} };
    testData.push_back(data);
}
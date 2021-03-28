#include "header.h"

void PrepareTestData(vector<TD_VVI_VI>& testData)
{
    TD_VVI_VI data;

    data.input = { {6, 9, 7} };
    data.output = { 6, 9, 7 };
    testData.push_back(data);

    data.input = { {6}, {9}, {7} };
    data.output = { 6, 9, 7 };
    testData.push_back(data);

    data.input = { {1,2,3} ,{4,5,6},{7,8,9} };
    data.output = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    testData.push_back(data);

    data.input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    data.output = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    testData.push_back(data);

}
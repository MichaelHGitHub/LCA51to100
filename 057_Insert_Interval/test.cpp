#include "header.h"


void PrepareTestData(vector<TD_VVI_VI_VVI>& testData)
{
    TD_VVI_VI_VVI data;

    data.input = { {0, 2},{5, 9 } };
    data.input2 = { 3, 4 };
    data.output = { {0, 2}, { 3, 4 }, {5, 9} };
    testData.push_back(data);

    data.input = { {0, 2},{4, 9 } };
    data.input2 = { 6, 8 };
    data.output = { {0, 2}, {4, 9} };
    testData.push_back(data);

    data.input = { {1, 5} };
    data.input2 = { 0, 0 };
    data.output = { {0, 0}, {1, 5} };
    testData.push_back(data);

    data.input = { {1, 5} };
    data.input2 = { 6, 8 };
    data.output = { {1, 5}, {6, 8} };
    testData.push_back(data);

    data.input = {{1, 3}, {6, 9}};
    data.input2 = {2, 5};
    data.output = {{1, 5}, {6, 9}};
    testData.push_back(data);

    data.input = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    data.input2 = {4, 8};
    data.output = {{1, 2}, {3, 10}, {12, 16}};
    testData.push_back(data);

    data.input = {};
    data.input2 = {5, 7};
    data.output = {{5, 7}};
    testData.push_back(data);

    data.input = {{1, 5}};
    data.input2 = {2, 3};
    data.output = {{1, 5}};
    testData.push_back(data);

    data.input = {{1, 5}};
    data.input2 = {2, 7};
    data.output = {{1, 7}};
    testData.push_back(data);
}
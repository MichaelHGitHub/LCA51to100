#include "header.h"

void PrepareTestData(vector<TD_VVI_VVI>& testData)
{
    TD_VVI_VVI data;

    //data.input = { {1} };
    //data.output = { {1} };
    //testData.push_back(data);

    //data.input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    //data.output = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    //testData.push_back(data);

    //data.input = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    //data.output = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    //testData.push_back(data);

    data.input = { {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0} };
    data.output = { {0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    testData.push_back(data);
}
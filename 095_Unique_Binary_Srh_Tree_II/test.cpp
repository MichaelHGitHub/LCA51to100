#include "header.h"

void PrepareTestData(vector<TD_I_VT>& testData)
{
    TD_I_VT data;

    data.input = 3;
    data.output = GenerateTrees({{1, NULL, 2, NULL, 3}, {1, NULL, 3, 2}, {2, 1, 3}, {3, 1, NULL, NULL, 2}, {3, 2, NULL, 1}} );
    testData.push_back(data);

    data.input = 1;
    data.output = GenerateTrees({{1}} );
    testData.push_back(data);

}
#include "header.h"

void PrepareTestData(vector<TD_S_S_S>& testData)
{
    TD_S_S_S data;

    data.input = "11";
    data.input2 = "1";
    data.output = "100";
    testData.push_back(data);

    data.input = "1010";
    data.input2 = "1011";
    data.output = "10101";
    testData.push_back(data);
}
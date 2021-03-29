#include "header.h"

void PrepareTestData(vector<TD_VVC_S_B>& testData)
{
    TD_VVC_S_B data;

    data.input = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    data.input2 = "ABCCED";
    data.output = true;
    testData.push_back(data);


    data.input = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    data.input2 = "SEE";
    data.output = true;
    testData.push_back(data);


    data.input = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    data.input2 = "ABCB";
    data.output = false;
    testData.push_back(data);


}
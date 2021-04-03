#include "header.h"

void PrepareTestData(vector<TD_L_I_I_L>& testData)
{
    TD_L_I_I_L data;

    data.input = GenerateLinkedList({ 1,2,3,4, 5, 6});
    data.input2 = 2;
    data.input3 = 5;
    data.output = GenerateLinkedList({ 1,5, 4, 3, 2, 6});
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.input2 = 2;
    data.input3 = 4;
    data.output = GenerateLinkedList({ 1,4,3,2,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 5 });
    data.input2 = 1;
    data.input3 = 1;
    data.output = GenerateLinkedList({ 5 });
    testData.push_back(data);
}
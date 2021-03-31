#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data;

    data.input = GenerateLinkedList({ });
    data.output = GenerateLinkedList({ });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,3,4,4,5 });
    data.output = GenerateLinkedList({ 1,2,5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,1,1,2,3 });
    data.output = GenerateLinkedList({ 2,3 });
    testData.push_back(data);
}
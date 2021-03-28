#include "header.h"

void PrepareTestData(vector<TD_L_I_L>& testData)
{
    TD_L_I_L data;

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.input2 = 2;
    data.output = GenerateLinkedList({ 4,5,1,2,3 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 0,1,2 });
    data.input2 = 4;
    data.output = GenerateLinkedList({ 2,0,1 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 0,1,2 });
    data.input2 = 0;
    data.output = GenerateLinkedList({ 0,1,2 });
    testData.push_back(data);

    data.input = GenerateLinkedList({});
    data.input2 = 3;
    data.output = GenerateLinkedList({});
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1 });
    data.input2 = 10;
    data.output = GenerateLinkedList({ 1 });
    testData.push_back(data);

}
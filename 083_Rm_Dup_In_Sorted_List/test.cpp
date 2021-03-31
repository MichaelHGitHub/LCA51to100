#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data;

    data.input = GenerateLinkedList({ 1,1, 1, 2, 2, 2, 3, 5 });
    data.output = GenerateLinkedList({ 1, 2, 3, 5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1, 1, 1,1,2 });
    data.output = GenerateLinkedList({ 1, 2 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,1, 1 });
    data.output = GenerateLinkedList({ 1 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,2,3,3,4,4,5 });
    data.output = GenerateLinkedList({ 1,2,3, 4, 5 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 1,1,2,3,3 });
    data.output = GenerateLinkedList({ 1,2,3 });
    testData.push_back(data);
}
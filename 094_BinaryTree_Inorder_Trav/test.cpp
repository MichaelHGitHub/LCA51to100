#include "header.h"

void PrepareTestData(vector<TD_T_VI>& testData)
{
    TD_T_VI data;

    data.input = GenerateTree({ 1, 2, 3, NULL, 4, 5, 6, 7, 8 });
    data.output = { 2 ,7 ,4 ,8 ,1 ,5 ,3 ,6 };
    testData.push_back(data);

    data.input = GenerateTree({ 1, NULL, 2, 3 });
    data.output = { 1,3,2 };
    testData.push_back(data);



    data.input = { };
    data.output = { };
    testData.push_back(data);

    data.input = GenerateTree({ 1 });
    data.output = { 1 };
    testData.push_back(data);

    data.input = GenerateTree({ 1, 2 });
    data.output = { 2,1 };
    testData.push_back(data);

    data.input = GenerateTree({ 1, NULL, 2 });
    data.output = { 1,2 };
    testData.push_back(data);
}
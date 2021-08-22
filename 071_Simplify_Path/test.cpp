#include "header.h"

void PrepareTestData(vector<TD_S_S>& testData)
{
    TD_S_S data;

    data.input = "/home/foo/bar/";
    data.output = "/home/foo/bar";
    testData.push_back(data);

    data.input = "/home/";
    data.output = "/home";
    testData.push_back(data);

    data.input = "/../";
    data.output = "/";
    testData.push_back(data);

    data.input = "/home//foo/";
    data.output = "/home/foo";
    testData.push_back(data);

    data.input = "/a/./b/../../c/";
    data.output = "/c";
    testData.push_back(data);

}
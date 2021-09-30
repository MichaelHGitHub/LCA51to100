#include "header.h"

void PrepareTestData(vector<TD_S_S_S_B>& testData)
{
    TD_S_S_S_B data;

    data.input = "aabcc";
    data.input2 = "dbbca";
    data.input3 = "aadbbcbcac";
    data.output = true;
    testData.push_back(data);

    data.input = "bcbccabcccbcbbbcbbacaaccccacbaccabaccbabccbabcaabbbccbbbaa";
    data.input2 = "ccbccaaccabacaabccaaccbabcbbaacacaccaacbacbbccccbac";
    data.input3 = "bccbcccabbccaccaccacbacbacbabbcbccbaaccbbaacbcbaacbacbaccaaccabcaccacaacbacbacccbbabcccccbababcaabcbbcccbbbaa";
    data.output = false;
    testData.push_back(data);

    data.input = "aabcc";
    data.input2 = "dbbca";
    data.input3 = "aadbcbbcac";
    data.output = true;
    testData.push_back(data);


    data.input = "";
    data.input2 = "b";
    data.input3 = "b";
    data.output = true;
    testData.push_back(data);

    data.input = "aabcc";
    data.input2 = "dbbca";
    data.input3 = "aadbbbaccc";
    data.output = false;
    testData.push_back(data);

    data.input = "";
    data.input2 = "";
    data.input3 = "";
    data.output = true;
    testData.push_back(data);
}
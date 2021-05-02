#include "header.h"

void PrepareTestData(vector<TD_S_VS>& testData)
{
    TD_S_VS data;

    data.input = "0000";
    data.output = { "0.0.0.0" };
    testData.push_back(data);

    data.input = "25525511135";
    data.output = { "255.255.11.135","255.255.111.35" };
    testData.push_back(data);

    data.input = "1111";
    data.output = { "1.1.1.1" };
    testData.push_back(data);

    data.input = "010010";
    data.output = { "0.10.0.10","0.100.1.0" };
    testData.push_back(data);

    data.input = "101023";
    data.output = { "1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3" };
    testData.push_back(data);

}
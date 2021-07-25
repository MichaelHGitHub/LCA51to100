#pragma once
#include "..\common\common.h"


void PrepareTestData(vector<TD_VVI_VI_VVI>& testData);

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

vector<vector<int>> insert_r(vector<vector<int>>& intervals, vector<int>& newInterval);
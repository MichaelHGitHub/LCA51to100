#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_VVC_S_B>& testData);

bool exist(vector<vector<char>>& board, string word);
bool exist2(vector<vector<char>>& board, string word);

bool exist_r(vector<vector<char>>& board, string word);
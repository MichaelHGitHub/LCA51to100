#pragma once

#include "../common/common.h"

void PrepareTestData(vector<TD_T_T_B>& testData);

bool isSameTree(TreeNode* p, TreeNode* q);

bool isSameTree_r(TreeNode* p, TreeNode* q);
bool isSameTree_r2(TreeNode* p, TreeNode* q);
#include "header.h"

vector<TreeNode*> buildSubBST(int begin, int end);

vector<TreeNode*> generateTrees_r(int n)
{
    return buildSubBST(1, n);
}

vector<TreeNode*> buildSubBST(int begin, int end)
{
    vector<TreeNode*> nodes;

    if (begin > end)
    {
        nodes.push_back(nullptr);
        return nodes;
    }

    for (int i = begin; i <= end; i++)
    {
        vector<TreeNode*> left_children = buildSubBST(begin, i - 1);
        vector<TreeNode*> right_children = buildSubBST(i + 1, end);

        for (int j = 0; j < left_children.size(); j++)
        {
            for (int k = 0; k < right_children.size(); k++)
            {
                nodes.push_back(new TreeNode(i, left_children[j], right_children[k]));
            }
        }
    }

    return nodes;
}
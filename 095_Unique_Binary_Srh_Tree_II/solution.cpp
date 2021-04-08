#include "header.h"


static vector<TreeNode*> createBSTree(int start, int end);

vector<TreeNode*> generateTrees(int n)
{
    vector<TreeNode*> roots = createBSTree(1, n);

    return roots;
}

vector<TreeNode*> createBSTree(int start, int end)
{
    vector<TreeNode*> roots;

    if (end < start)
    {
        roots.push_back( nullptr);
        return roots;
    }

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode*> left_children = createBSTree(start, i - 1);
        vector<TreeNode*> right_children = createBSTree(i+ 1, end);

        for (int j = 0; j < left_children.size(); j++)
        {
            for (int k = 0; k < right_children.size(); k++)
            {
                // Has to new the node here so that every combination has its
                // own object. 
                TreeNode* node = new TreeNode(i);

                node->left = left_children[j];
                node->right = right_children[k];

                roots.push_back(node);
            }
        }
    }

    return roots;
}
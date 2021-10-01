#include "header.h"

bool isBSTNode(TreeNode* node, TreeNode** pre);

bool isValidBST_r(TreeNode* root)
{
    TreeNode* pre = nullptr;
    return isBSTNode(root, &pre);
}

bool isBSTNode(TreeNode* node, TreeNode** pre)
{
    if (!node)
    {
        return true;
    }

    if (!isBSTNode(node->left, pre))
    {
        return false;
    }

    if (*pre && node->val <= (*pre)->val)
    {
        return false;
    }

    *pre = node;

    return isBSTNode(node->right, pre);
}
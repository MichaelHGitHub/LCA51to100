#include "header.h"

static bool checkBST(TreeNode* root, TreeNode* min_node, TreeNode* max_node);

// Pass the current node as max node to left sub-tree, it can ensure its
// left child's children less than its value. then recurrsion can ensure its
// desendants also less than the current node.
// Same idea for right sub-tree, only difference is to make larger instead of less.
bool isValidBST2(TreeNode* root)
{
    if (!checkBST(root, NULL, NULL))
    {
        return false;
    }

    return true;
}

static bool checkBST(TreeNode* root, TreeNode* min_node, TreeNode* max_node)
{
    if (root == nullptr)
    {
        return true;
    }
    if ((min_node != nullptr && root->val <= min_node->val) ||
        max_node != nullptr && root->val >= max_node->val)
    {
        return false;
    }

    return checkBST(root->left, min_node, root) && checkBST(root->right, root, max_node);
}
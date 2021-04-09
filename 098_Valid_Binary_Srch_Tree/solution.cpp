#include "header.h"

static bool checkBST(TreeNode* root, int& max_val, int& min_val);

// Besides checking if the current node is larger than left and less than right node.
// also need to know the max value from left sub-tree and min value from right
// sub-tree and check if they are all good.
bool isValidBST(TreeNode* root)
{
    int max_val = INT32_MIN, min_val = INT32_MAX;
    if (!checkBST(root, max_val, min_val))
    {
        return false;
    }

    return true;
}

bool checkBST(TreeNode* root, int& max_val, int& min_val)
{
    int max_left = INT32_MIN, min_left = INT32_MAX;
    if (root->left != nullptr)
    {
        // Check left sub-tree and get its max and min values
        if (!checkBST(root->left, max_left, min_left))
        {
            return false;
        }
        // Check current value against left sub-tree
        if (root->val <= max_left)
        {
            return false;
        }
    }
    max_left = root->val;

    int max_right = INT32_MIN, min_right = INT32_MAX;
    if (root->right != nullptr)
    {
        // Check right sub-tree and get its max and min values
        if (!checkBST(root->right, max_right, min_right))
        {
            return false;
        }
        // Check current value against its right sub-tree
        if (root->val >= min_right)
        {
            return false;
        }
    }
    min_right = root->val;

    // Retuen the max and min value of the current tree.
    max_val = max(max_left, max_right);
    min_val = min(min_left, min_right);

    return true;
}
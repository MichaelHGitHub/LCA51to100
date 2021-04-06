#include "header.h"

static void helper(vector<int>& result, TreeNode* root);

// Recursive solution
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    helper(result, root);
    return result;
}

static void helper(vector<int>& result, TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    helper(result, root->left);
    result.push_back(root->val);
    helper(result, root->right);
}
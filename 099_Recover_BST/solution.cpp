#include "header.h"

bool findWrongNodes(TreeNode* node, TreeNode** pre, TreeNode** wrong1, TreeNode** wrong2);

// Visit the BST in inorder order, if the current node is not larger than the previously visited node:
// --- first occur, the previous node is the first node that needs to be swapped.
// --- second occur, the current node is the second node that needs to be swapped.
// --- If such thing occurs only once, previously visited and current nodes need to be swapped.

void recoverTree(TreeNode* root)
{
    TreeNode *pre = nullptr, *wrong1 = nullptr, *wrong2 = nullptr;
    findWrongNodes(root, &pre, &wrong1, &wrong2);

    int val = wrong1->val;
    wrong1->val = wrong2->val;
    wrong2->val = val;
}

bool findWrongNodes(TreeNode* node, TreeNode** pre, TreeNode** wrong1, TreeNode** wrong2)
{
    if (!node)
    {
        return true;
    }

    if (!findWrongNodes(node->left, pre, wrong1, wrong2))
    {
        return false;
    }

    if (*pre && (*pre)->val >= node->val)
    {
        if (!*wrong1)
        {
            *wrong1 = *pre;
            *wrong2 = node;
        }
        else
        {
            *wrong2 = node;
            return false;
        }
    }

    *pre = node;

    if (!findWrongNodes(node->right, pre, wrong1, wrong2))
    {
        return false;
    }

    return true;
}
#include "header.h"
#include <stack>
#include <unordered_set>

bool isValidBST_r2(TreeNode* root)
{
    std::stack<TreeNode*> pending;
    std::unordered_set<TreeNode*> visited;

    if (!root)
    {
        return true;
    }

    pending.push(root);
    TreeNode* last_visit = nullptr;

    while (!pending.empty())
    {
        TreeNode* node = pending.top();

        if (node->left && visited.find(node->left) == visited.end())
        {
            pending.push(node->left);
        }
        else
        {
            if (last_visit && node->val <= last_visit->val)
            {
                return false;
            }

            visited.insert(node);
            last_visit = node;
            pending.pop();

            if (node->right)
            {
                pending.push(node->right);
            }
        }
    }

    return true;
}
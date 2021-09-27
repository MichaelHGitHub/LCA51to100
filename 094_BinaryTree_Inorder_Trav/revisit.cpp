#include "header.h"
#include <stack>
#include <unordered_set>

vector<int> inorderTraversal_r(TreeNode* root)
{
    vector<int> results;
    std::stack<TreeNode*> pending;
    std::unordered_set<TreeNode*> visited;

    if (root)
    {
        pending.push(root);

        while (!pending.empty())
        {
            TreeNode* node = pending.top();
            if (node->left && visited.find(node->left) == visited.end())
            {
                pending.push(node->left);
            }
            else
            {
                results.push_back(node->val);
                visited.insert(node);
                pending.pop();

                if (node->right)
                {
                    pending.push(node->right);
                }
            }
        }
    }

    return results;
}
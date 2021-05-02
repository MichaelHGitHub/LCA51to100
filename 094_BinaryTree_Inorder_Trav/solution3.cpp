#include <stack>
#include <unordered_set>
#include "header.h"

vector<int> inorderTraversal3(TreeNode* root) {

    vector<int> result;

    if (!root)
    {
        return result;
    }

    stack<TreeNode*> pending;
    unordered_set<TreeNode*> visited;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode* node = pending.top();
        bool left_visited = node->left ? (visited.find(node->left) != visited.end()) : true;
        if (left_visited)
        {
            result.push_back(node->val);
            pending.pop();
            visited.insert(node);

            if (node->right)
            {
                pending.push(node->right);
            }
        }
        else
        {
            pending.push(node->left);
        }
    }
    return result;
}
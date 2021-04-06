#include <stack>
#include "header.h"

// Recursive solution
vector<int> preOrderTraversal(TreeNode* root)
{
    stack<TreeNode*> nodes;
    vector<int> result;

    nodes.push(root);

    while (root != nullptr && !nodes.empty())
    {
        root = nodes.top();
        nodes.pop();

        if (root != nullptr)
        {
            result.push_back(root->val);

            // Push right first so that visit left first
            if (root->right)
            {
                nodes.push(root->right);
            }

            if (root->left)
            {
                nodes.push(root->left);
            }
        }

    }

    return result;
}

// Recursive solution
vector<int> preOrderTraversal2(TreeNode* root)
{
    stack<TreeNode*> nodes;
    vector<int> result;

    while (root != nullptr || !nodes.empty())
    {
        if (root == nullptr)
        {
            root = nodes.top();
            nodes.pop();
        }
        result.push_back(root->val);

        // Save the right child
        if (root->right != nullptr)
        {
            nodes.push(root->right);
        }
        root = root->left;
    }

    return result;
}
#include <stack>
#include <unordered_set>
#include "header.h"

vector<int> postOrderTraversal(TreeNode* root)
{
    vector<int> result;

    stack<TreeNode*> nodes;
    unordered_set<TreeNode*> visited;

    while (root != nullptr || !nodes.empty())
    {
        if (root != nullptr)
        {
            // Save the current node
            nodes.push(root);

            // Try left if exists.
            if (root->left != nullptr)
            {
                root = root->left;
            }
            else
            {
                // Otherwise try right
                root = root->right;
            }
        }
        else
        {
            // Retrieve node from saved ones.
            root = nodes.top();

            // The right child could be visited already
            if (root->right != nullptr &&
                visited.find(root->right) == visited.end())
            {
                root = root->right;
            }
            else
            {
                // Right child is visite or null, visit the current node.
                result.push_back(root->val);
                nodes.pop();
                visited.insert(root);

                // assign null so that retrive another node from the stack
                root = nullptr;
            }
        }
    }

    return result;
}
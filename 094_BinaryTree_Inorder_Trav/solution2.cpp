#include <stack>
#include "header.h"

// Non-recursive solution
vector<int> inorderTraversal2(TreeNode* root)
{
    vector<int> result;
    stack<TreeNode*> nodes;

    while (root || !nodes.empty())
    {
        if (root != nullptr)
        {
            if (root->left != nullptr)
            {
                nodes.push(root);
                root = root->left;
            }
            else
            {
                result.push_back(root->val);

                // Note: Since node itself and its left child are 
                // all handled, move to right child here.
                root = root->right;
            }
        }
        else
        {
            root = nodes.top();
            nodes.pop();
            result.push_back(root->val);

            // For the node retrieved from stack, its 
            root = root->right;
        }

    }

    return result;
}
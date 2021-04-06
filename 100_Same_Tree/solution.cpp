#include <stack>
#include "header.h"

// Use pre-order traversal, compare each of the node. 
// Note: unlike regual traversal, the null node can't be
// left out without comparing.
bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if ((p != nullptr && q == nullptr) ||
        (p == nullptr && q != nullptr))
    {
        return false;
    }

    bool result = true;

    stack<TreeNode*> nodes_p, nodes_q;
    nodes_p.push(p);
    nodes_q.push(q);

    while (!nodes_p.empty() && !nodes_q.empty())
    {
        p = nodes_p.top();
        nodes_p.pop();

        q = nodes_q.top();
        nodes_q.pop();

        if (p == nullptr && q == nullptr)
        {
            continue;
        }

        if ((p != nullptr && q == nullptr) ||
            (p == nullptr && q != nullptr))
        {
            result = false;
            break;
        }

        if (p->val != q->val)
        {
            result = false;
            break;
        }

        // Push right first so that visit it last
        nodes_p.push(p->right);
        nodes_p.push(p->left);

        nodes_q.push(q->right);
        nodes_q.push(q->left);

    }

    if (!nodes_p.empty() || !nodes_q.empty())
    {
        result = false;
    }

    return result;
}
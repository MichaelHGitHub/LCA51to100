#include "header.h"
#include <stack>

bool isSameTree_r(TreeNode* p, TreeNode* q)
{    bool result = true;
    std::stack<TreeNode*> pending_p;
    std::stack<TreeNode*> pending_q;

    if (p)
    {
        pending_p.push(p);
    }

    if (q)
    {
        pending_q.push(q);
    }

    while (!pending_p.empty() && !pending_q.empty())
    {
        TreeNode* n_p = pending_p.top();
        pending_p.pop();
        TreeNode* n_q = pending_q.top();
        pending_q.pop();

        if (n_p->val != n_q->val)
        {
            result = false;
            break;
        }

        if ((!n_p->left && n_q->left) ||
            (n_p->left && !n_q->left) ||
            (!n_p->right && n_q->right) ||
            (n_p->right && !n_q->right))
        {
            result = false;
            break;
        }

        if (n_p->right)
        {
            pending_p.push(n_p->right);
        }

        if (n_p->left)
        {
            pending_p.push(n_p->left);
        }

        if (n_q->right)
        {
            pending_q.push(n_q->right);
        }

        if (n_q->left)
        {
            pending_q.push(n_q->left);
        }
    }

    if (!pending_p.empty() || !pending_q.empty())
    {
        result = false;
    }

    return result;

}
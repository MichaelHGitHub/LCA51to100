#include "header.h"

bool isSameTree_r2(TreeNode* p, TreeNode* q)
{
    if (!p && !q)
    {
        return true;
    }

    if ((p && !q) || (!p && q))
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree_r2(p->left, q->left) && isSameTree_r2(p->right, q->right);
}
#include "header.h"

// One pointer
// If P->val = P->next->val, p->next should be removed
ListNode* deleteDuplicates2(ListNode* head)
{
    ListNode* p = head;
    

    while (p)
    {
        if (p->next && p->val == p->next->val)
        {
            p->next = p->next->next;
        }
        else
        {
            p = p->next;
        }
    }

    return head;
}
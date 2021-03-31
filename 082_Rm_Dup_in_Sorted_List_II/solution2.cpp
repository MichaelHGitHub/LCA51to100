#include "header.h"

// One pointe and one flag
// Check p->next->val and p->next->next->val, if equal, skip one node 
// and mark the other so that it can be deleted later. 
ListNode* deleteDuplicates2(ListNode* head)
{
    ListNode dummy = ListNode(200, head);

    ListNode* index = &dummy;
    bool remove_next = false;

    while (index)
    {
        if (index->next && index->next->next && index->next->val == index->next->next->val)
        {
            index->next = index->next->next;

            // Mark the next node should be removed too. 
            remove_next = true;
        }
        else
        {
            if (remove_next && index->next)
            {
                index->next = index->next->next;
            }
            else
            {
                index = index->next;
            }

            // In this case, next node should be kept
            remove_next = false;
        }

    }

    return dummy.next;
}
#include "header.h"

ListNode* partition_r(ListNode* head, int x)
{
    ListNode dummy(0, head);

    ListNode* part = &dummy;
    ListNode* pre = part;
    ListNode* cur = head;

    while (cur)
    {
        if (cur->val < x)
        {
            if (part->next != cur)
            {
                pre->next = cur->next;
                cur->next = part->next;
                part->next = cur;
                cur = pre->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
            part = part->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

    return dummy.next;
}
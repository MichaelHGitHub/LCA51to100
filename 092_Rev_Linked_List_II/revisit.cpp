#include "header.h"

ListNode* reverseBetween_r(ListNode* head, int left, int right)
{
    ListNode dummy(0, head);
    ListNode* insert_pos = &dummy;

    ListNode* pre = &dummy;
    ListNode* cur = head;
    int index = 1;

    while (cur)
    {
        if (index < left)
        {
            insert_pos = insert_pos->next;
            pre = cur;
            cur = cur->next;
        }
        else if (index == left)
        {
            pre = cur;
            cur = cur->next;
        }
        else if (index > left && index <= right)
        {
            pre->next = cur->next;
            cur->next = insert_pos->next;
            insert_pos->next = cur;
            cur = pre->next;
        }
        else
        {
            break;
        }

        ++index;
    }

    return dummy.next;
}
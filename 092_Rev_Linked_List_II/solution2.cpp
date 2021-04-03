#include "header.h"

// One pass:
// It can be done to convert pre->A->B->C->post to pre->C->B->A->post within one pass,
// only need to remember the pos of A, and then link A to its new joint post.
ListNode* reverseBetween2(ListNode* head, int left, int right)
{
    if (left == right)
    {
        return head;
    }

    ListNode dummy(0, head);
    ListNode* pre = &dummy;
    ListNode* joint1 = head;
    ListNode* joint2 = nullptr;

    while (left > 1)
    {
        pre = joint1;
        joint1 = joint1->next;

        --left;
        --right;
    }

    joint2 = joint1->next;

    while (right > 1 && joint2)
    {
        ListNode* temp = joint2->next;
        joint2->next = pre->next;
        pre->next = joint2;

        joint2 = temp;
        --right;
    }

    // Don't for get to link the broken joint
    // Joint2 now is the first post node after reverst phase
    joint1->next = joint2;

    return dummy.next;
}
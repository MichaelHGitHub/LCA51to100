#include "header.h"

// Two pointers
// P1: start of a section of same numbers
// P2: one place next to the end of the same numbers
ListNode* deleteDuplicates(ListNode* head)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode* start = head;
    ListNode* end = head->next;

    while (end)
    {
        if (start->val != end->val)
        {
            // Drop some nodes
            if (start->next != end)
            {
                start->next = end;
            }

            // Reset start
            start = end;
        }

        end = end->next;
    }

    // Do forget to remove last duplication
    start->next = end;

    return head;
}
#include "header.h"

// Three pointers
// p1: last to be kept node
// p2: start of the duplication
// p3: one place next to the end of the duplication
ListNode* deleteDuplicates(ListNode* head)
{
    ListNode dummy = ListNode(200, head);

    ListNode* index = &dummy;
    ListNode* start = &dummy;
    ListNode* end = start->next;

    while (end)
    {
        if (start->val != end->val)
        {
            if (start->next != end)
            {
                // There are nodes to skip
                index->next = end;
            }
            else
            {
                // Start is proven good, no skipping is need
                index = start;
            }
            // reset start
            start = end;
        }
        end = end->next;
    }

    // Do forget to handle last bunch of duplicate numbers
    if (start->next != end)
    {
        index->next = end;
    }

    return dummy.next;
}
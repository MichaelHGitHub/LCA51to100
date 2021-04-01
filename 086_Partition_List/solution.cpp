#include "header.h"

// Two pointers
// p1: point at the last node less than x, aka insertion point.
// p2: point at the current node, whose next node value will be checked against x.
ListNode* partition(ListNode* head, int x)
{
    ListNode dummy(0, head);

    // Insert_pos points at the last node less than x.
    ListNode* insert_pos = &dummy;
    // Node points at a node whose next node is being checked up.
    ListNode* node = insert_pos;

    while (node->next)
    {
        if (node->next->val < x)
        {
            if (node != insert_pos)
            {
                // Need to insert node next after insert_pos

                ListNode* temp = insert_pos->next;
                insert_pos->next = node->next;
                node->next = node->next->next;
                insert_pos->next->next = temp;

                insert_pos = insert_pos->next;
            }
            else
            {
                // No insertion is needed. 

                insert_pos = node->next;
                node = node->next;
            }
        }
        else
        {
            node = node->next;
        }
    }

    return dummy.next;
}
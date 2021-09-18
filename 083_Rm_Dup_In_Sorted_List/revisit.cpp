#include "header.h"

void deleteNodes(ListNode* begin, ListNode* end);

ListNode* deleteDuplicates_r(ListNode* head)
{
    ListNode* cur = head;
    ListNode* next = head? head->next : nullptr;

    while (next)
    {
        if (cur->val != next->val)
        {
            ListNode* del = cur->next;
            cur->next = next;

            deleteNodes(del, next);

            cur = next;
        }
        next = next->next;
    }
    if (cur)
    {
        ListNode* del = cur->next;
        cur->next = nullptr;

        deleteNodes(del, nullptr);
    }
    return head;
}

void deleteNodes(ListNode* begin, ListNode* end)
{
    while (begin != end)
    {
        ListNode* del = begin;
        begin = begin->next;
        delete del;
    }
}
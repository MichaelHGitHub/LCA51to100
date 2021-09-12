#include "header.h"

static void deleteNodes(ListNode* begin, ListNode* end);

ListNode* deleteDuplicates_r(ListNode* head)
{
    ListNode dummy(0, head);
    ListNode* pre = &dummy;
    ListNode* cur = head;
    ListNode* next = head ? head->next : nullptr;

    while (next)
    {
        if (next->val == cur->val)
        {
            next = next->next;
        }
        else if (next != cur->next)
        {
            ListNode* begin = cur;
            ListNode* end = next;

            pre->next = next;
            cur = pre->next;
            next = next->next;

            deleteNodes(begin, end);
        }
        else
        {
            pre = cur;
            cur = next;
            next = next->next;
        }
    }

    if (cur && next != cur->next)
    {
        pre->next = nullptr;
    }
    return dummy.next;
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
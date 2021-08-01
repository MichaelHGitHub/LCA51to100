#include "header.h"

ListNode* rotateRight_r(ListNode* head, int k)
{
    ListNode dummy;
    vector< ListNode*> nodes;
    ListNode* node = head;

    while (node)
    {
        nodes.push_back(node);
        node = node->next;
    }

    if (nodes.size())
    {
        int dividing_point = nodes.size() - (k % nodes.size());
        node = &dummy;

        for (int i = dividing_point; i < nodes.size(); i++)
        {
            node->next = nodes[i];
            node = node->next;
        }
        for (int i = 0; i < dividing_point; i++)
        {
            node->next = nodes[i];
            node = node->next;
        }
        node->next = NULL;
    }

    return dummy.next;
}
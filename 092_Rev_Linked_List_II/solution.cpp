#include "header.h"

// Two passes:
// Put all the nodes to an array, the rest of the work is then
// easy and simple.
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (left == right)
    {
        return head;
    }

    ListNode dummy(0, head);
    vector<ListNode*> nodes;
    nodes.push_back(&dummy);

    ListNode* node = head;
    while (node != nullptr)
    {
        nodes.push_back(node);
        node = node->next;
    }
    nodes.push_back(nullptr);

    while (right > left)
    {
        ListNode* temp = nodes[left];
        nodes[left] = nodes[right];
        nodes[right] = temp;

        nodes[left-1]->next = nodes[left];
        nodes[left]->next = nodes[left + 1];
        nodes[right - 1]->next = nodes[right];
        nodes[right]->next = nodes[right + 1];

        ++left;
        --right;
    }

    return dummy.next;
}
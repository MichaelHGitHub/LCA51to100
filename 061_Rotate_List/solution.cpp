#include "header.h"

// First we need to know the length of the list by looping through
// the list, meanwhile save the node pointers in an array(nodes) so that
// we can quickly retrieve the pointer later.
// the steps we really need to move is (k % list_length). 
// the index of new head is (nodes.size() - move). 
// 
ListNode* rotateRight(ListNode* head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    vector< ListNode*> nodes;
    ListNode* p = head;
    while (p != nullptr)
    {
        nodes.push_back(p);
        p = p->next;
    }

    int move = k % nodes.size();
    ListNode* new_head = nullptr;
    if(nodes.size() == 1)
    {
        new_head = head;
    }
    else if (move == 0)
    {
        new_head = head;
    }
    else
    {
        // set new head
        new_head = nodes[nodes.size() - move];
        // connect the old end and head
        nodes[nodes.size() - 1]->next = head;
        // set new end next
        nodes[nodes.size() - move - 1]->next = nullptr;
    }

    return new_head;
}
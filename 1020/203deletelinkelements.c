/**
 * Definition for singly-linked list.
 * 
 */
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
  
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* temp;
    while(head && head->val == val)
    {
        temp = head;//暂存将被释放的结点
        head = head->next;
        free(temp);
    }

    struct ListNode* cur = head;
    while(cur && (temp = cur->next))
    {
        if(temp->val == val)
        {
            cur->next = temp->next;
            free(temp);
        }
        else
            cur = cur->next;
    }
    return head;
}

struct ListNode* removeElements(struct ListNode* head, int val)
{
    typedef struct ListNode ListNode;
    ListNode* shead;
    shead = (ListNode*)malloc(sizeof(ListNode));
    shead->next = head;
    ListNode* cur = shead;

    while(cur->next != NULL)
    {
        if(cur->next->val == val)
        {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        else
        {
            cur = cur->next;
        }
    }
    head = shead->next;
    free(shead);
    return head;
}
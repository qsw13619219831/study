//反转一个单链表。

//示例:

//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* result=NULL;
    struct ListNode*c=head;
    while(c!=NULL){
       struct ListNode* next=c->next;
        c->next=result;
        result=c;
        c=next;
        
    }
    return result;
}
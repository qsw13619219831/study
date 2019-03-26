//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode*c=head;
    if(c==NULL||c->next==NULL){return head;}
    int count=1;
    while(c->next!=NULL){
        count ++;
       c=c->next;
    }
     c->next=head;
  int a = (count - k > 0) ? count - k :count- (k%count);
    for(int i=0;i<a;i++){
        c=c->next;
    }
   struct ListNode*new=c->next;
    c->next=NULL;
    return new;
}
/*给定一个链表和一个特定值 x，对链表进行分隔，
使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode*l1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*l2=(struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next=NULL;
    l2->next=NULL;
    struct ListNode*r,*p,*q;
    r=head;
    p=l1;
    q=l2;
    if(r==NULL||r->next==NULL){return r;}
    while(r!=NULL){
        if(r->val<x){
            p->next=r;
            r=r->next;
            p=p->next;
            p->next=NULL;
            }
        else{
            q->next=r;
            r=r->next;
            q=q->next;
            q->next=NULL;
        }       
            }
    if(l1->next==NULL){
        return l2->next;
    }
    else if(l2->next==NULL){
        return l1->next;
    }
   
    p->next=l2->next;
    return l1->next;
    
}
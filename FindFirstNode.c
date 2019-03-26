/*编写一个程序，找到两个单链表相交的起始节点。*/
	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode*a=headA;
    struct ListNode*b=headB;
    if(a==NULL||b==NULL){return NULL;}
    int counta=0;
    int countb=0;
    while(a!=NULL||b!=NULL){//遍历得出两个链表长度
        if(a!=NULL){
            a=a->next;
            counta++;
        }
        if(b!=NULL){
            b=b->next;
            countb++;
        }
    }
    struct ListNode*aa=headA;
      struct ListNode*bb=headB;
     
    if(counta>countb){
        for(int i=0;i<(counta-countb);i++){
            aa=aa->next;
        }
    }
    else if(countb>counta){
        for(int i=0;i<(countb-counta);i++){
            bb=bb->next;
        }
    }
    
    while(aa!=NULL){
        if(aa==bb){
            return aa;
        }
        else{
            aa=aa->next;
            bb=bb->next;
        }
    }
    return NULL;
}
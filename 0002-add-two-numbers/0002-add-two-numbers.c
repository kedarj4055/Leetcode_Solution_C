/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *temp=malloc(sizeof(struct ListNode));
    int sum,carry=0;
    temp->val=0;
    temp->next=NULL;
    struct ListNode *temp1=temp;
    while(l1!=NULL || l2!=NULL || carry!=0){
        int sum = carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        struct ListNode *newn=malloc(sizeof(struct ListNode));
        newn->val=sum%10;
        newn->next=NULL;
        temp->next=newn;
        temp=newn;
    }
    return temp1->next;
}
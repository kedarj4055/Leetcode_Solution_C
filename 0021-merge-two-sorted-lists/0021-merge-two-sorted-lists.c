/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode temp,*temp1=&temp;
    while(list1!=NULL&&list2!=NULL){
        if(list1->val<=list2->val){
            temp1->next=list1;
            list1=list1->next;
        }
        else{
            temp1->next=list2;
            list2=list2->next;
        }
        temp1=temp1->next;
    }
    temp1->next=(list1!=NULL)?list1:list2;
    return temp.next;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode *prev=NULL,*next=NULL,*tem=head;
     while(tem!=NULL)
     {
         next=tem->next;
         tem->next=prev;
         prev=tem;
         tem=next;
         
     }
        head=prev;
        return head;
    }
};
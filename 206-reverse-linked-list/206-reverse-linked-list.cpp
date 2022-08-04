
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
//      ListNode *prev=NULL,*next=NULL;
//      while(head!=NULL)
//      {
//          next=head->next;
//          head->next=prev;
//          prev=head;
//          head=next;
         
//      }
//         return prev;
        return reverse(head,NULL);
    }
    ListNode* reverse(ListNode* head,ListNode *n)
    {
        if(head==NULL) return n;
        ListNode*  next=head->next;
        head->next=n;
        return reverse(next,head);
    }
};
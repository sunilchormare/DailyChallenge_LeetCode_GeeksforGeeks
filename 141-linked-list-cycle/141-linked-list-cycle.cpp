class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head==NULL) return false;
        ListNode *fast=head,*slow=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
         fast=fast->next->next;
         slow=slow->next;
            if(slow==fast)
                return true;
        }
            
        
            return false;
    }
};

// if(head==null) return false;
//     ListNode walker = head;
//     ListNode runner = head;
//     while(runner.next!=null && runner.next.next!=null) {
//         walker = walker.next;
//         runner = runner.next.next;
//         if(walker==runner) return true;
//     }
//     return false;
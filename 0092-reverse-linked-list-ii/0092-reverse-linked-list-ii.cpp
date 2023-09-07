
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(head == NULL || m ==n) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        dummy->next = head;
        for(int i = 0; i < m-1;i++) {
            prev = prev->next;
        }
        ListNode *tail = prev->next;
        
        for(int i = 0; i < n-m; i++) {
            ListNode *tmp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = tmp;
        }
        return dummy->next;       
    }
};
/*
Complexity
Time Complexity : O(n)
Spave Complexity: O(1)
*/    
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(head == NULL || head->next == NULL) return head;
        ListNode *list = head;
         while(list->next != NULL) 
         {
             if (list->val == list->next->val)
                 list->next = list->next->next;
             else 
                 list = list->next;
         }

         return head;
    }
};
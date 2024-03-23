/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
      void reorderList(ListNode *head) {
      if (head == NULL || head->next == NULL)
          return;
      
      ListNode *prev = NULL, *slow = head, *fast = head, *l1 = head;
      
      while (fast != NULL  && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      
      prev->next = NULL;
      
      // step 2. reverse the 2nd half
      ListNode *l2 = reverse(slow);
      
      // step 3. merge the two halves
      merge(l1, l2);
    }
    
    ListNode* reverse(ListNode *head) {
      ListNode *prev = NULL, *curr = head, *next = NULL;
      
      while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      
      return prev;
    }
    
     void merge(ListNode *head1, ListNode *head2) {
        while (head2 != NULL) {
            ListNode *next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = next;
        }
    }
};
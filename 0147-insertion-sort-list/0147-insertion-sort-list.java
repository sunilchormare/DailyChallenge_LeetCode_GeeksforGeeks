
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( head == NULL ){
			return head;
		}
		
		ListNode* helper = new ListNode(0); 
		ListNode* cur = head; 
		ListNode* pre = helper; 
		ListNode* next = NULL;
	
		while( cur != NULL ){
			next = cur->next;
		
			while( pre->next != NULL && pre->next->val < cur->val ){
				pre = pre->next;
			}
	
			cur->next = pre->next;
			pre->next = cur;
			pre = helper;
			cur = next;
		}
		
		return helper->next;
    }
};
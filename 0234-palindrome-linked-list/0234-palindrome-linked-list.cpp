
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *slow=head;
        while(slow!=NULL)
        {
                s.push(slow->val);
                slow=slow->next;
            
        }
        while(head!=NULL)
        {int i=s.top();
          s.pop();
          if(head->val!=i)
              return false;
         head=head->next;
            
        }
        return true;
    }
};
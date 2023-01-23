
class Solution {
    public boolean isPalindrome(ListNode head) {
         Stack<Integer> s=new Stack<>();
        ListNode slow=head;
        while(slow!=null)
        {
                s.push(slow.val);
                slow=slow.next;
            
        }
        while(head!=null)
        {int i=s.pop();
          
          if(head.val!=i)
              return false;
         head=head.next;
            
        }
        return true;
    }
}
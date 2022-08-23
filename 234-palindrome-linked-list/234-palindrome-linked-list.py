
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        s=[]
        slow=head
        while(slow):
                s.append(slow.val)
                slow=slow.next
        while(head):
            i=s.pop();
            if(head.val!=i):
                return False
            head=head.next
        return True
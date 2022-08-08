class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return null;
        ListNode p=head;
        int len=1;
        while(p.next!=null)
        {
            len++;
            p=p.next;
        }
        p.next=head;
        k=len-k%len;
        while(k-->0)
         p=p.next;
        head=p.next;
        p.next=null;
        return head;
    }
}
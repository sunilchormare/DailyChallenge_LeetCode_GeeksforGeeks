/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  ListNode head = null;
    Random r = new Random();

    public Solution(ListNode head) {
        this.head = head;
    }
    
    public int getRandom() {
        int result = this.head.val;
        ListNode node = this.head.next;
        int k =1;
        int i = 1;
        while(node != null){
            double x = r.nextDouble();
            double y = k / (k+i *1.0);           
            if(x <= y){
                result = node.val;
            }
            
            i++;
            node = node.next;
        }
        
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
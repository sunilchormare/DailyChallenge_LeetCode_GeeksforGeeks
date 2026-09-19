// class Solution {
//      ListNode merge2Lists(ListNode l1, ListNode l2) {
//         if (l1==null) return l2;
//         if (l2==null) return l1;
//         ListNode head = l1.val <= l2.val? l1 : l2;
//         head.next = l1.val <= l2.val ? merge2Lists(l1.next, l2) : merge2Lists(l1, l2.next);
//         return head;
//     }
//     public ListNode mergeKLists(ListNode[] lists) {
//         if (lists.length == 0) return null;
        
//         ListNode head = lists[0];
        
//         for (int i = 1; i < lists.length; i++)
//             head = merge2Lists(head, lists[i]);
        
//         return head;
//     }
// }

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> minHeap =
            new PriorityQueue<>((a, b) -> Integer.compare(a.val, b.val));

        // Add the first node of every non-empty list.
        for (ListNode head : lists) {
            if (head != null) {
                minHeap.offer(head);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!minHeap.isEmpty()) {
            ListNode node = minHeap.poll();

            tail.next = node;
            tail = tail.next;

            // Add the next node from the same list.
            if (node.next != null) {
                minHeap.offer(node.next);
            }
        }

        tail.next = null;

        return dummy.next;
    }
}
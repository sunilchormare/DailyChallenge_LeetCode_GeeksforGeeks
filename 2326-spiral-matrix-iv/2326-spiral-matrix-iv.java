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
   public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] spiral = new int[m][n];
        for(int[] row : spiral)
            Arrays.fill(row, -1);
        int r = 0, c = 0, ri = 0, ci = 1;
        while(head != null){
            spiral[r][c] = head.val;
            head = head.next;
            if(spiral[(r+ri+m) % m][(c+ci+n) % n] != -1){
                int temp = ri;
                ri = ci;
                ci = -temp;
            }
            r += ri;
            c += ci;
        }
        return spiral;
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        
//         List<List<Integer>> ans=new LinkedList<List<Integer>>();
//         Queue<TreeNode> q=new LinkedList<TreeNode>();
//         q.offer(root);
//         while(!q.isEmpty())
//         {
//             int levelNum = q.size();
//             List<Integer> subList = new LinkedList<Integer>();
            
//          for(int i=0;i<levelNum;i++)
//             {
//                 if(q.peek().left != null) q.offer(q.peek().left);
//                 if(q.peek().right != null) q.offer(q.peek().right);
//                 subList.add(q.poll().val);
//             }
//             ans.add(subList);
            
//         }
        
        
//         return ans;
        
        List<List<Integer>> res = new LinkedList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null) q.add(root);
        
        while (!q.isEmpty()) {
            int levelSize = q.size();
            List<Integer> level = new ArrayList<>(levelSize);
            for (int i = 0; i < levelSize; i++) {
                TreeNode cur = q.poll();
                if (cur.left != null) q.add(cur.left);
                if (cur.right != null) q.add(cur.right);
                level.add(cur.val);
            }
            res.add(level);
        }
        
        return res;
    }
}
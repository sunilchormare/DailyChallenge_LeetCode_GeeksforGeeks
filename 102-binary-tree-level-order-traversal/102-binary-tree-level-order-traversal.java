class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
     List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> q =new LinkedList<>();
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
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
         TreeNode root = null;
        Map<Integer,TreeNode> map = new HashMap<>();
        for(int [] des : descriptions) {
            map.put(des[1], new TreeNode(des[1]));
        }
        for(int [] des : descriptions) {
            if(!map.containsKey(des[0])) {
                root = new TreeNode(des[0]);
                map.put(des[0],root);
            }
            TreeNode parent = map.get(des[0]);
            TreeNode cur =  map.get(des[1]);
            if(des[2] == 1){
                parent.left = cur;
            }else{
                parent.right = cur;
            }
        }
        return root;
    }
}
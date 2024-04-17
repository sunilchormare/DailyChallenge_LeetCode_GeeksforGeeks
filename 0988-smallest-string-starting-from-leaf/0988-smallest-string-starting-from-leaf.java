class Solution {
    public String smallestFromLeaf(TreeNode root) {
        return smallestFromLeaf(root,"");
    }
    
    public String smallestFromLeaf(TreeNode root, String suffix) {
        String cur = String.valueOf((char)('a'+root.val)).concat(suffix);
        if(root.left==null&&root.right==null){
            return cur;
        }
        
        String left = null;
        String right = null;
        if(root.left!=null) {
            left = smallestFromLeaf(root.left, cur);
        }
        if(root.right!=null) {
            right = smallestFromLeaf(root.right, cur);
        }
        if(left!=null&&right!=null){
            return left.compareTo(right)<0?left:right;
        } else if(left==null){
            return right;
        } else {
            return left;
        }
    }
}
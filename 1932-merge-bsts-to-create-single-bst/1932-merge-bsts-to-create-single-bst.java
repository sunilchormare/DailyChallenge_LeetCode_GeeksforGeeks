class Solution {
  public TreeNode canMerge(List<TreeNode> trees) {
    Map<Integer, TreeNode> map = new HashMap<>(); // root.val -> root 
    Map<Integer, Integer> count = new HashMap<>(); // node.val -> count
    for(TreeNode tree : trees){
      map.put(tree.val, tree);
      count.put(tree.val, count.getOrDefault(tree.val, 0) + 1); 
      if(tree.left != null)
        count.put(tree.left.val, count.getOrDefault(tree.left.val, 0) + 1); 
      if(tree.right != null)
        count.put(tree.right.val, count.getOrDefault(tree.right.val, 0) + 1); 
    }
    
    for(TreeNode root : trees)
      if(count.get(root.val) == 1)
        return traverse(root, map, Integer.MIN_VALUE, Integer.MAX_VALUE) && map.size() == 1 ? root : null; 
    return null;
  }
  
  private boolean traverse(TreeNode root, Map<Integer, TreeNode> map, int min, int max){
    if(root == null)
      return true; 
    if(root.val <= min || root.val >= max)
      return false; 
    
    if(root.left == null && root.right == null){ // leaf node
      if(map.containsKey(root.val) && root != map.get(root.val)){
        TreeNode next = map.get(root.val); 
        root.left = next.left; 
        root.right = next.right; 
        map.remove(root.val); 
      }
    }
    return traverse(root.left, map, min, root.val) && traverse(root.right, map, root.val, max); 
  }
}
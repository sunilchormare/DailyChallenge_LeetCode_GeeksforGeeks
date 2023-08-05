
class Solution {
   public List<TreeNode> generateTrees(int n) {
    
    if(n==0){
        return null;
    }
    
    return solve(1 ,n);   
}

public List<TreeNode> solve(int start ,int end){
    
    if(start>end){
        ArrayList<TreeNode> al = new ArrayList();
        al.add(null);
        return al;
    }
    
    List<TreeNode> treeList = new ArrayList();
    
    for(int curr=start;curr<=end;curr++){
        
        List<TreeNode> leftTrees = solve(start ,curr-1);
        List<TreeNode> rightTrees = solve(curr+1 ,end);
        
        for(int l=0;l<leftTrees.size();l++){
            for(int r=0;r<rightTrees.size();r++){
                
                TreeNode node = new TreeNode(curr);
                
                node.left = leftTrees.get(l);
                node.right = rightTrees.get(r);
                
                treeList.add(node);
            }   
        }
    }
    
    return treeList; 
}
}
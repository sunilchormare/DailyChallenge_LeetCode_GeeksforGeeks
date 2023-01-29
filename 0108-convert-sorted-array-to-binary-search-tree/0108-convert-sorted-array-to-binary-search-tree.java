class Solution {
      public TreeNode constructTreeFromArray(int[] nums,int left,int right)
    {
        if(left>right) return null;
        int mid=left+(right-left)/2;
        TreeNode node=new TreeNode(nums[mid]);
        node.left=constructTreeFromArray(nums,left,mid-1);
        node.right=constructTreeFromArray(nums,mid+1,right);
        return node;
        
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0) return null;
        return constructTreeFromArray(nums,0,nums.length-1);
        
    }
    
  
}
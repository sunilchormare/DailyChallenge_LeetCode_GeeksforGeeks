
class Solution {
    public TreeNode bstFromPreorder(int[] a) {
         int i=0;
        return buildBST(a,new int[]{0},Integer.MAX_VALUE);
    }
   public TreeNode buildBST(int []a,int i[],int bound)
    {
        if(i[0]==a.length||a[i[0]]>bound) return null;
        TreeNode root=new TreeNode(a[i[0]++]);
        root.left=buildBST(a,i,root.val);
        root.right=buildBST(a,i,bound);
        return root;
    }
}
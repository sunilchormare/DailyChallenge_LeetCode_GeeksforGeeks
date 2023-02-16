class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if(root==None):
            return 0   
        ls=self.maxDepth(root.left)
        rs=self.maxDepth(root.right)
        return (1+max(ls,rs))       
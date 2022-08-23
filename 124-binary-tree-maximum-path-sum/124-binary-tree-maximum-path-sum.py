class Solution:
    maxInt = -float('inf')
    def maxPathSum(self, root: Optional[TreeNode]) -> int: 
        def helper(root: TreeNode) -> int:
            if not root:    return 0
            l = max(0,helper(root.left))
            r = max(0,helper(root.right))
            self.maxInt = max(self.maxInt,l + r + root.val)
            return max(l,r) + root.val
        if not root:    return 0
        helper(root)
        return self.maxInt

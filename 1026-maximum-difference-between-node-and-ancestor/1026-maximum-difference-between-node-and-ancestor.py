# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(root,mn,mx)->int:
            if (root==None) :
                return mx - mn
            mx = max(mx, root.val)
            mn = min(mn, root.val)
            return max(dfs(root.left, mn, mx), dfs(root.right, mn, mx))
        return dfs(root,root.val,root.val)
        

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
         def dfs(root,maxVal):
            if not root: return 0
            res=1 if(root.val>=maxVal) else 0
            res+=dfs(root.left,max(maxVal,root.val))
            res+=dfs(root.right,max(maxVal,root.val))
            return res
         return dfs(root,root.val)
        
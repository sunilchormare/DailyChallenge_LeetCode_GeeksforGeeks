# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
            q,res = [root],[]
            if not root: return res
            while len(q):
                s=len(q)
                sum=0
                for i in range(s):
                    node=q.pop(0)
                    sum+=node.val
                    if(node.left): q.append(node.left)
                    if(node.right): q.append(node.right)
                res.append(sum/s)
            return res
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], v: int, d: int) -> Optional[TreeNode]:
        if d < 2:
            node = TreeNode(v)
            node.left = root if d == 1 else None
            node.right = root if d == 0 else None
            return node
        elif root:
            root.left = self.addOneRow(root.left, v, d - 1 if d > 2 else 1)
            root.right = self.addOneRow(root.right, v, d - 1 if d > 2 else 0)
            return root
        
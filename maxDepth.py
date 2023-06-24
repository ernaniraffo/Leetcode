# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root:
            q = [(root, 1)]
            max_depth = 1
            while q:
                n, depth = q.pop(0)
                max_depth = max(max_depth, depth)
                if n.left:
                    q.append((n.left, depth + 1))
                if n.right:
                    q.append((n.right, depth + 1))
            return max_depth
        return 0

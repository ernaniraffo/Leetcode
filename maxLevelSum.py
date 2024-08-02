# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxLevelSum(self, root: Optional[TreeNode]) -> int:

        max_sum = dict()
        q = [(root, 1)]
        level = 1

        while q:
            n, level = q.pop()
            max_sum[level] = n.val if level not in max_sum else max_sum[level] + n.val
            if n.left:
                q.append((n.left, level + 1))
            if n.right:
                q.append((n.right, level + 1))

        return max(max_sum, key=max_sum.get)

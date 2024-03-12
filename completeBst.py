# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = [root]
        lastNode = False
        while q:
            n = q.pop(0)
            if n is None:
                lastNode = True
            else:
                if lastNode:
                    return False
                q.append(n.left)
                q.append(n.right)
        return True

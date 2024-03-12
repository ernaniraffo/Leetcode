# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isLeaf(self, node: TreeNode) -> bool:
        return not node.left and not node.right

    def isGoal(self, node: TreeNode, target: int, pathSum: int):
        return pathSum == target and self.isLeaf(node)

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root:
            if self.isGoal(root, targetSum, root.val):
                return True
            q = [(root, root.val)]
            while q:
                node, path_sum = q.pop(0)
                if node.left:
                    new_path_sum = node.left.val + path_sum
                    if self.isGoal(node.left, targetSum, new_path_sum):
                        return True
                    q.append((node.left, new_path_sum))
                if node.right:
                    new_path_sum = node.right.val + path_sum
                    if self.isGoal(node.right, targetSum, new_path_sum):
                        return True
                    q.append((node.right, new_path_sum))
        return False

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorderMapping = {inorder[i]: i for i in range(len(inorder))}
        rootIndx = 0

        def arrayToTree(left, right):
            nonlocal rootIndx
            if left > right:
                return None

            root_val = preorder[rootIndx]
            rootIndx += 1

            root = TreeNode(root_val)
            mid = inorderMapping[root_val]

            root.left = arrayToTree(left, mid - 1)
            root.right = arrayToTree(mid + 1, right)
            return root

        return arrayToTree(0, len(inorder) - 1)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorderMapping = {inorder[i] : i for i in range(len(inorder))}
        rootIndx = len(postorder) - 1
        
        def arrayToTree(left, right):
            nonlocal rootIndx
            if left > right:
                return None
            
            root_val = postorder[rootIndx]
            mid = inorderMapping[root_val]
            root = TreeNode(root_val)
            
            rootIndx -= 1

            root.right = arrayToTree(mid+1, right)
            root.left = arrayToTree(left, mid-1)
            return root

        return arrayToTree(0, rootIndx)

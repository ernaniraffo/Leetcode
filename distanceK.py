# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        
        def add_parent(child: TreeNode, parent: TreeNode):
            if child:
                child.parent = parent
                add_parent(child.left, child)
                add_parent(child.right, child)
        
        add_parent(root, None)

        visited = set()
        sol = []
        def dfs(node: TreeNode, distance: int):
            if node and node not in visited:
                visited.add(node)
                if distance == k:
                    sol.append(node.val)
                dfs(node.parent, distance + 1)
                dfs(node.left, distance + 1) 
                dfs(node.right, distance + 1)

        dfs(target, 0)
        return sol

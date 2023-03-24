class Solution:
    def __init__(self):
        self.count = 0

    def dfs(self, root: int, parent: int, adj: DefaultDict[int, tuple]):
        for node, direction in adj[root]:
            if node != parent:
                self.count += direction
                self.dfs(node, root, adj)
        return

    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = defaultdict(list)
        for src, dest in connections:
            adj[src].append((dest, 1))
            adj[dest].append((src, 0))

        self.dfs(0, -1, adj)
        return self.count


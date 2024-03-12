class Solution:

    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        pairs = 0
        componentSize = 0
        remainingNodes = n
        visited = set()

        def dfs(n: int, adj: DefaultDict[int, List[int]], visited: set):
            visited.add(n)
            count = 1
            for node in adj[n]:
                if node not in visited:
                    count += dfs(node, adj, visited)
            return count

        for i in range(n):
            if remainingNodes > 0 and i not in visited:
                componentSize = dfs(i, adj, visited)
                remainingNodes -= componentSize
                pairs += componentSize * remainingNodes

        return pairs

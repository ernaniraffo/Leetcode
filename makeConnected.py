class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if (len(connections) < n - 1):
            return -1
    
        adj = DefaultDict(list)
        for connection in connections:
            adj[connection[0]].append(connection[1])
            adj[connection[1]].append(connection[0])

        def dfs(node: int, adj: DefaultDict[int, List[int]], visited: set):
            visited.add(node)
            for n in adj[node]:
                if (n not in visited):
                    dfs(n, adj, visited)

        visited = set()
        connected = 0
        for i in range(n):
            if i not in visited:
                connected += 1
                dfs(i, adj, visited)

        return connected - 1
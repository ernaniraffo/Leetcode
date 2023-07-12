class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        def dfs(node: int, visited: set, stack: list):            
            if stack[node]:
                return False
            if node in visited:
                return True
            visited.add(node)
            stack[node] = True
            for child in graph[node]:
                if not dfs(child, visited, stack):
                    return False
            stack[node] = False
            return True
        visited = set()
        stack = [False] * len(graph) 
        for i in range(len(graph)):
            dfs(i, visited, stack)
        return [i for i in range(len(graph)) if not stack[i]]

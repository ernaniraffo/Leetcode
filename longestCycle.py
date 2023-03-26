class Solution:
    def __init__(self):
        self.cycle = -1

    def dfs(self, node: int, edges: List[int], visited: set, distance: DefaultDict[int, int]):
        visited.add(node)
        neighbor = edges[node]

        if neighbor != -1 and neighbor not in visited:
            distance[neighbor] = distance[node] + 1
            self.dfs(neighbor, edges, visited, distance)
        elif neighbor != -1 and neighbor in distance:
            self.cycle = max(self.cycle, distance[node] - distance[neighbor] + 1)

    def longestCycle(self, edges: List[int]) -> int:
        visited = set()
        for i in range(len(edges)):
            if i not in visited:
                distance = defaultdict(int)
                distance[i] = 1
                self.dfs(i, edges, visited, distance)
        return self.cycle
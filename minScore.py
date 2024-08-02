class Solution:

    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = defaultdict(list)
        for road in roads:
            adj[road[0]].append((road[1], road[2]))
            adj[road[1]].append((road[0], road[2]))
        visited = {1}
        q = [1]
        score = sys.maxsize
        while q:
            n = q.pop(0)
            for node, distance in adj[n]:
                score = min(score, distance)
                if node not in visited:
                    visited.add(node)
                    q.append(node)
        return score

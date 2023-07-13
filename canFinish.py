class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = defaultdict(int)
        adj = defaultdict(list)
        for pre in prerequisites:
            adj[pre[1]].append(pre[0])
            indegree[pre[0]] += 1

        q = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
                
        visited = 0
        while q:
            n = q.popleft()
            visited += 1
            for neighbor in adj[n]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return visited == numCourses

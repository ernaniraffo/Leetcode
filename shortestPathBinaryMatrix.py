class Solution:
    def neighbors(self, i, j):
        up = (i - 1, j)
        down = (i + 1, j)
        left = (i, j - 1)
        right = (i, j + 1)
        up_left = (i - 1, j - 1)
        up_right = (i - 1, j + 1)
        down_left = (i + 1, j - 1)
        down_right = (i + 1, j + 1)
        return [up, down, left, right, up_left, up_right, down_left, down_right]

    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        q = []
        visited = set()
        n, m = len(grid), len(grid[0])
        
        if grid[0][0] == 0:
            q.append((0,0,1))
            visited.add((0,0))
        
        while q:
            i, j, v = q.pop(0)
            if i == n - 1 and j == m - 1:
                return v
            for row, col in self.neighbors(i, j):
                if (0 <= row < n and 0 <= col < m and (row, col) not in visited):
                    if grid[row][col] == 0:
                        visited.add((row, col))
                        q.append((row, col, v + 1))
        return -1

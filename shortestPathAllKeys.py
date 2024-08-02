from collections import deque, defaultdict
from typing import List


class Solution:

    def shortestPathAllKeys(self, grid: List[str]) -> int:

        m = len(grid)
        n = len(grid[0])

        locks = {"A", "B", "C", "D", "E", "F"}
        keys = {"a", "b", "c", "d", "e", "f"}
        keys_needed = 0

        for i in range(m):
            for j in range(n):
                cell = grid[i][j]
                if cell == '@':
                    start = (i, j)
                elif cell in keys:
                    keys_needed |= (1 << (ord(cell) - ord('a')))

        q = deque()
        q.append((start, 0, 0))
        visited = set()

        while q:
            state = q.popleft()
            pos, keys_obtained, steps = state
            i, j = pos

            for di, dj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= di < m and 0 <= dj < n:
                    cell = grid[di][dj]
                    if cell != '#':
                        if cell in keys and not ((1 << (ord(cell) - ord('a'))) & keys_obtained):
                            new_keys = keys_obtained | (1 << (ord(cell) - ord('a')))
                            if new_keys == keys_needed:
                                return steps + 1
                            visited.add(((di, dj), new_keys))
                            q.append(((di, dj), new_keys, steps + 1))
                        elif cell in locks and not (keys_obtained & (1 << (ord(cell) - ord('A')))):
                            continue
                        elif ((di, dj), keys_obtained) not in visited:
                            visited.add(((di, dj), keys_obtained))
                            q.append(((di, dj), keys_obtained, steps + 1))
        return -1


if __name__ == "__main__":
    grid = [".#.b.", "A.#aB", "#d...", "@.cC.", "D...#"]
    s = Solution()
    print(s.shortestPathAllKeys(grid))

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        m = len(board)
        n = len(board[0])

        def dfs(start: tuple, length: int):
            i, j = start
            temp = board[i][j]
            board[i][j] = '-'
            for di, dj in [(i, j - 1), (i, j + 1), (i + 1, j), (i - 1, j)]:
                if 0 <= di < m and 0 <= dj < n and board[di][dj] != '-':
                    if board[di][dj] == word[length]:
                        if length == len(word) - 1 or dfs((di, dj), length + 1):
                            return True
            board[i][j] = temp
            return False

        for i in range(m):
            for j in range(n):
                if len(word) == 1 and board[i][j] == word:
                    return True
                if board[i][j] == word[0] and dfs((i, j), 1):
                    return True
        return False

if __name__ == "__main__":
    board = [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
    word = "ABCESEEDFE"
    s = Solution()
    print(s.exist(board, word))

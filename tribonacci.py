class Solution:

    def tribonacci(self, n: int) -> int:
        max_n = 38
        F = [0] * max_n
        F[0] = 0
        F[1], F[2] = 1, 1
        if n < 3:
            return F[n]
        curr = 3
        while curr <= n:
            F[curr] = F[curr - 3] + F[curr - 2] + F[curr - 1]
            curr += 1
        return F[n]

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if (x == 0):
            return 0
        if (n == 0):
            return 1
            
        power = abs(n)
        res = self.myPow(x, power // 2)
        if (n % 2 == 0):
            res *= res
        else:
            res *= (x * res)
        return res if n > 0 else (1/res)

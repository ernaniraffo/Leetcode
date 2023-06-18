class Solution:
    def mySqrt(self, x: int) -> int:
        if (x == 0 or x == 1):
            return x
        lo = 1
        hi = x
        while lo <= hi:
            mid = (lo + hi) // 2
            if mid * mid < x:
                lo = mid + 1
            elif mid * mid > x:
                hi = mid - 1
            else:
                return mid
        return hi

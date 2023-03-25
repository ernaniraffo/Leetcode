class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        n = abs(x)
        while n > 0:
            last_digit = n % 10
            ans = ans * 10 + last_digit
            n //= 10
        if x < 0:
            ans *= -1
        if ans < -(2**31) or ans > (2**31)-1:
            return 0
        return ans

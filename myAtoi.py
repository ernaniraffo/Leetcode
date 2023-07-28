class Solution:
    def myAtoi(self, s: str) -> int:
        res = 0

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        i = 0
        while i < len(s) and s[i] == ' ':
            i += 1

        if i >= len(s):
            return 0
        
        negative = False
        if s[i] == '-':
            negative = True
            i += 1
        elif s[i] == '+':
            i += 1

        while i < len(s) and s[i].isdigit():
            if res > INT_MAX // 10 or (res == INT_MAX // 10 and s[i] - '0' > 7):
                return INT_MAX if not negative else INT_MIN
            res = (res * 10) + s[i] - '0'
            i += 1

        return res if not negative else res * -1
        

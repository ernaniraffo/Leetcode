class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        sumString = ""

        aP = len(a) - 1
        bP = len(b) - 1

        while aP >= 0 or bP >= 0 or carry:
            
            res = carry
            
            if aP >= 0:
                res += int(a[aP])
                aP -= 1

            if bP >= 0:
                res += int(b[bP])
                bP -= 1

            carry = res // 2
            res = res % 2
            sumString = str(res) + sumString

        return sumString

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        opening = {'(', '{', '['}
        for c in s:
            if c in opening:
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                top = stack.pop()
                if c == ')' and top != '(':
                    return False
                elif c == '}' and top != '{':
                    return False
                elif c == ']' and top != '[':
                    return False
        return len(stack) == 0

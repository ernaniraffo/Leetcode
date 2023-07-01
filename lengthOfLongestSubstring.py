class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m = {}
        longest = 0
        i = 0
        for j in range(len(s)):
            c = s[j]
            if c in m and m[c] >= i:
                i = m[c] + 1
            m[c] = j
            longest = max(longest, (j-i)+1)
        return longest

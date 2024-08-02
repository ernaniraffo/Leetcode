class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:

        def backtrack(curr: List[int]) -> None:
            if len(nums) == len(curr):
                ans.append(curr.copy())
                return
            for num in nums:
                if num not in curr:
                    curr.append(num)
                    backtrack(curr)
                    curr.pop()

        ans = []
        backtrack([])
        return ans

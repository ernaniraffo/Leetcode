class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        sorted_arr = sorted(arr)
        diff = None
        for i in range(len(sorted_arr)-1):
            if diff is None:
                diff = abs(sorted_arr[i] - sorted_arr[i + 1])
            else:
                new_diff = abs(sorted_arr[i] - sorted_arr[i + 1])
                if new_diff != diff:
                    return False
        return True

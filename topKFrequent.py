class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        heap = []

        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        for num in freq:
            heappush(heap, (freq[num], num))
            if len(heap) > k:
                heappop(heap)

        return [i[1] for i in heap]
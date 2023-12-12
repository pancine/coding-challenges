import heapq


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        result = heapq.nlargest(2, nums)

        return (result[0] - 1) * (result[1] - 1)

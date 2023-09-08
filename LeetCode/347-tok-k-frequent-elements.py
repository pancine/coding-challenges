class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        numbers = {}

        for val in nums:
            numbers[val] = numbers.get(val, 0) + 1

        x = map(lambda x: x[0], sorted(numbers.items(), key=lambda x: x[1], reverse=True))

        return list(x)[:k]

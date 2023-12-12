class Counter(dict):
    def __missing__(self, key):
        return 0


class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        occurences = Counter()

        for num in arr:
            occurences[num] += 1

        return max(occurences, key=occurences.get)

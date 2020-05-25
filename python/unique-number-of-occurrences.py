class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d=collections.Counter(arr)
        s=set()
        for k, v in d.items():
            if v in s: return False
            s.add(v)
        return True


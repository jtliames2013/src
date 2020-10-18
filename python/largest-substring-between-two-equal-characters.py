class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        res=-1
        dic=collections.defaultdict(int)
        for i, c in enumerate(s):
            if c in dic:
                res=max(res, i-dic[c]-1)
            else:
                dic[c]=i
        return res


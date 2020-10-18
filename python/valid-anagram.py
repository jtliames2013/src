class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t): return False
        dic=collections.defaultdict(int)
        for c in s: dic[c]+=1
        for c in t:
            dic[c]-=1
            if dic[c]<0: return False
        return True


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n, dic=len(words), defaultdict(int)
        for w in words:
            for c in w:
                dic[c]+=1
        
        for v in dic.values():
            if v%n!=0: return False
        return True


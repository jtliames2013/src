class Solution:
    def smaller(self, c1, c2):
        res=0
        for c in 'abcdefghijklmnopqrstuvwxyz':
            res+=c1[c]-c2[c]
            if res>0: return False
        return True
    
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        c1=collections.Counter(s1)
        c2=collections.Counter(s2)
        return self.smaller(c1, c2) or self.smaller(c2, c1)


class Solution:
    def sortSentence(self, s: str) -> str:
        l=s.split()
        res=[None]*len(l)
        for w in l:
            res[int(w[-1])-1]=w[:-1]
        return ' '.join(res)


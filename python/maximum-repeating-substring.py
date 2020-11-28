1.
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        res=1
        while sequence.find(word*res)!=-1: res+=1
        return res-1

2.
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        n, res, i=len(sequence), 0, 0
        while i<n:
            if sequence[i]==word[0]:
                l, j=0, 0
                while i<n:
                    if sequence[i]!=word[j]: break
                    i+=1
                    j+=1
                    if j==len(word):
                        j=0
                        l+=1
                i-=j-1
                res=max(res, l)
            else:
                i+=1
        return res

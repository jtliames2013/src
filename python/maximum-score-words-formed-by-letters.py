class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def dfs(start, total):
            nonlocal res
            res=max(res, total)
            for i in range(start, len(words)):
                valid=True
                sums=0
                for c in words[i]:
                    if d[c]==0: valid=False
                    d[c]-=1
                    sums+=score[ord(c)-ord('a')]
                    
                if valid: dfs(i+1, total+sums)
                for c in words[i]: d[c]+=1
        
        d=collections.Counter(letters)
        res=float('-inf')
        dfs(0, 0)
        return res


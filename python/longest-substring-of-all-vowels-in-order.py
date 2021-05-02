class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        res, len, cnt=0, 0, 0
        for i, c in enumerate(word):
            if i==0 or c>word[i-1]:
                len+=1
                cnt+=1
            elif c==word[i-1]:
                len+=1
            else:
                len=cnt=1
            if cnt==5: res=max(res, len)
        return res


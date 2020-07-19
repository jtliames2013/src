class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        def getRight(i):
            res=r[ord(s[i])-ord('a')]
            j=i
            while j<res:
                if i>l[ord(s[j])-ord('a')]: return -1
                res=max(res, r[ord(s[j])-ord('a')])
                j+=1
            return res
            
        res, n=[], len(s)
        l, r=[float('inf')]*26, [float('-inf')]*26
        for i in range(n):
            l[ord(s[i])-ord('a')]=min(l[ord(s[i])-ord('a')], i)
            r[ord(s[i])-ord('a')]=max(r[ord(s[i])-ord('a')], i)
        
        right=float('-inf')
        for i in range(n):
            if i==l[ord(s[i])-ord('a')]:
                currRight=getRight(i)
                if currRight==-1: continue
                if i>right: res.append("")
                right=currRight
                res[-1]=s[i:right+1]
                
        return res

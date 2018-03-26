class Solution:
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        res=[]
        for c in num:
            while len(res)>0 and c<res[-1] and k>0:
                res.pop()
                k-=1
            res.append(c)
        
        return ''.join(res[:-k or None]).lstrip('0') or "0"

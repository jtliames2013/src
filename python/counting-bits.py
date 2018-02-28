class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res=[0]*(num+1)
        if num==0: return res
        
        res[1]=1        
        for i in range(2, num+1):
            res[i]=res[i>>1]+(1 if (i & 0x1)==1 else 0)
        return res
        

class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res=[]
        output=[]
        self.getSum(res, output, k, n, 1)
        return res
    
    def getSum(self, res, output, k, n, start):
        if k==0:
            if n==0:
                res.append(list(output))
            return
        
        for i in range(start, 10):
            if n-i>=0:
                output.append(i)
                self.getSum(res, output, k-1, n-i, i+1)
                output.pop()

class Solution:
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        res, end=1, math.sqrt(2*N)
        for i in range(2, math.ceil(end)):
            if (N-i*(i-1)/2)%i==0: res+=1        
        return res

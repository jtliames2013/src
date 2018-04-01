class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count=0
        isPrime=[True] * n
        for i in range(2, int(n**0.5)+1):
            if isPrime[i]==False: continue
            for j in range(i*i, n, i):
                isPrime[j]=False
        
        for i in range(2, n):
            if isPrime[i]: count+=1
                
        return count


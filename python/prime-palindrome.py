class Solution:
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        def isPrime(n):
            if n<2: return False            
            for i in range(2, int(math.sqrt(n))+1):                
                if n%i==0: return False
            return True
        
        if 8<=N<=11: return 11
        for i in range(1, 10**5):
            n=int(str(i)+str(i)[-2::-1])
            if n>=N and isPrime(n): return n
        return -1

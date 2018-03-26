1. iterative
class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        count=0
        while n>1:
            if (n & 0x1)==0: n>>=1
            elif n==3 or ((n>>1) & 0x1)==0: n-=1
            else: n+=1
            count+=1
        return count

2. recursive
class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        def dfs(n):
            if n==1: return 0
            if n==3: return 2
            if (n & 0x1)==0: return dfs(n>>1)+1
            elif ((n>>1) & 0x1)==0: return dfs(n-1)+1
            else: return dfs(n+1)+1
            
        return dfs(n)

class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        start, i, n=0, 0, len(S)
        res=[]
        while i<n:
            while i<n and S[i]==S[start]: i+=1
            if i-start>=3: res.append((start, i-1))
            start=i
                
        return res

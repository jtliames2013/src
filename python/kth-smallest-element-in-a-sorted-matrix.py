class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        m=len(matrix)
        if m==0: return 0
        n=len(matrix[0])
        if n==0: return 0
        
        h=[]
        heapq.heappush(h, [matrix[0][0], 0, 0])
        while len(h)>0 and k>0:
            k-=1
            v, i, j=heapq.heappop(h)
            if k==0: return v
            if i<m-1:
                heapq.heappush(h, [matrix[i+1][j], i+1, j])
            if i==0 and j<n-1:
                heapq.heappush(h, [matrix[i][j+1], i, j+1])
        
        return 0                    

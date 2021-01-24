class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        m, n=len(matrix), len(matrix[0])
        for i in range(m):
            for j in range(n):
                if i>0: matrix[i][j]^=matrix[i-1][j]
                if j>0: matrix[i][j]^=matrix[i][j-1]
                if i>0 and j>0: matrix[i][j]^=matrix[i-1][j-1]
        
        pq=[]
        for i in range(m):
            for j in range(n):
                if len(pq)<k:
                    heappush(pq, matrix[i][j])
                elif matrix[i][j]>pq[0]:
                    heappop(pq)
                    heappush(pq, matrix[i][j])
                    
        return pq[0]


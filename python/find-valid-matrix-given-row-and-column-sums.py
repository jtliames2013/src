1.
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n=len(rowSum), len(colSum)
        res=[[0 for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                res[i][j]=min(rowSum[i], colSum[j])
                rowSum[i]-=res[i][j]
                colSum[j]-=res[i][j]

        return res

2.
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n, i, j=len(rowSum), len(colSum), 0, 0
        res=[[0 for j in range(n)] for i in range(m)]
        while i<m and j<n:
            res[i][j]=min(rowSum[i], colSum[j])
            rowSum[i]-=res[i][j]
            colSum[j]-=res[i][j]
            if rowSum[i]==0: i+=1
            if colSum[j]==0: j+=1
        
        return res
        

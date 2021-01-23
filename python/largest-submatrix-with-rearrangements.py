class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        res, m, n=0, len(matrix), len(matrix[0])
        height=[0]*n
        for i in range(m):
            for j in range(n):
                height[j]=0 if matrix[i][j]==0 else height[j]+1
            sorted_height=sorted(height)
            for j in range(n):
                res=max(res, sorted_height[j]*(n-j))
        return res


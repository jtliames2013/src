class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n, res=len(mat), [True]*4
        for i in range(n):
            for j in range(n):
                if mat[i][j]!=target[i][j]: res[0]=False
                if mat[i][j]!=target[j][n-i-1]: res[1]=False
                if mat[i][j]!=target[n-i-1][n-j-1]: res[2]=False
                if mat[i][j]!=target[n-j-1][i]: res[3]=False
        return res[0] or res[1] or res[2] or res[3]


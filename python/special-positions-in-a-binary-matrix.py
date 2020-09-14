class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        res, m, n=0, len(mat), len(mat[0])
        rowCnt, colCnt=[0]*m, [0]*n
        for i in range(m):
            for j in range(n):
                if mat[i][j]==1:
                    rowCnt[i]+=1
                    colCnt[j]+=1

        for i in range(m):
            for j in range(n):
                if mat[i][j]==1 and rowCnt[i]==1 and colCnt[j]==1:
                    res+=1
        return res


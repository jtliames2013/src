class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []
        m, n=len(matrix), len(matrix[0])
        total, row, col=m*n, 0, 0
        res=[0]*total
        
        for i in range(total):
            res[i]=matrix[row][col]
            if (row+col)%2==0:
                if col==n-1: row+=1
                elif row==0: col+=1
                else:
                    row-=1
                    col+=1
            else:
                if row==m-1: col+=1
                elif col==0: row+=1
                else:
                    row+=1
                    col-=1
        return res

2.
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []
        m, n=len(matrix), len(matrix[0])
        res, d=[], collections.defaultdict(list)
        for i in range(m):
            for j in range(n):
                d[i+j].append(matrix[i][j])

        for k in d.keys():
            if k%2==0: d[k].reverse()
            res+=d[k]
        return res


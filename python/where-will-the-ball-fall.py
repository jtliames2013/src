class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n=len(grid), len(grid[0])
        res=[-1]*n
        for j in range(n):
            col, i=j, 0
            while i<m:
                if grid[i][col]==1 and col<n-1 and grid[i][col+1]==1:
                    col+=1
                elif grid[i][col]==-1 and col>0 and grid[i][col-1]==-1:
                    col-=1
                else:
                    break
                i+=1
            if i==m: res[j]=col
            
        return res


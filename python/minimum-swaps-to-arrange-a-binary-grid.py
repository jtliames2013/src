class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        m, n, res=len(grid), len(grid[0]), 0
        cnt=[0]*m
        for i in range(m):
            count=0
            for j in range(n-1, -1, -1):
                if grid[i][j]==1: break
                count+=1
            cnt[i]=count
        for i in range(m):
            found=False
            for j in range(i, m):
                if cnt[j]>=m-i-1:
                    found=True
                    break
            if found==False: return -1
            res+=j-i
            cnt=cnt[:i]+cnt[j:j+1]+cnt[i:j]+cnt[j+1:]
        return res
        

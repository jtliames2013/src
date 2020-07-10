class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        def countOne(count):
            n=len(count)
            sums, stk=[0]*n, []
            for i in range(n):
                while stk and count[i]<=count[stk[-1]]: stk.pop()
                    
                if not stk: sums[i]=count[i]*(i+1)
                else: sums[i]=sums[stk[-1]]+count[i]*(i-stk[-1])
                stk.append(i)
            return sum(sums)
        
        res, m, n=0, len(mat), len(mat[0])
        count=[0]*n
        for i in range(m):
            for j in range(n):
                count[j]=count[j]+1 if mat[i][j]==1 else 0
            res+=countOne(count)
        return res


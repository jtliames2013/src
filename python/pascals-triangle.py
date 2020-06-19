class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res=[]
        for i in range(numRows):
            r=[0]*(i+1)
            r[0]=r[-1]=1
            for j in range(1, len(r)-1):
                r[j]=res[i-1][j-1]+res[i-1][j]
            res.append(r)
            
        return res

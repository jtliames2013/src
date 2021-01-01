class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        r, c=destination
        res=[]
        steps, down=r+c, r
        for i in range(r+c):
            steps-=1
            num=comb(steps, down)
            if num>=k:
                res.append('H')
            else:
                k-=num
                down-=1
                res.append('V')
        
        return ''.join(res)


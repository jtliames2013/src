class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        res=float('inf')
        ones=[i for i, v in enumerate(nums) if v==1]
        n=len(ones)
        sums=[0]*(n+1)
        for i in range(1, n+1):
            sums[i]=sums[i-1]+ones[i-1]
            
        for i in range(n-k+1):
            res=min(res, sums[i+k]-sums[i+(k+1)//2]-sums[i+k//2]+sums[i])
            
        # odd: (1+2+...+k/2)*2 = (k/2)*(k/2+1)
        # even: (1+2+...+k/2-1)*2 + k/2 = (k/2)*(k/2)
        return res-(k//2)*((k+1)//2)


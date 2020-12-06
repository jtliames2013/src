class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        mod=10**9+7
        mx=max(instructions)
        res, tree=0, [0]*(mx+1)
        
        def get(i):
            res=0
            while i>0:
                res+=tree[i]
                i-=(i&-i)
            return res
            
        def update(i):
            while i<=mx:
                tree[i]+=1
                i+=(i&-i)
        
        for i, v in enumerate(instructions):
            res+=min(get(v-1), i-get(v))
            update(v)
            
        return res%mod


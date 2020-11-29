1.
class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        def dfs(start):
            if start==len(quantity): return True
            for k, v in cnt.items():
                if v>=quantity[start]:
                    cnt[k]-=quantity[start]
                    if dfs(start+1): return True
                    cnt[k]+=quantity[start]
            return False

        cnt=collections.Counter(nums)
        quantity.sort(reverse=True)
        return dfs(0)

2.
class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        @lru_cache(None)
        def dfs(start, mask):
            if mask==(1<<m)-1: return True
            if start==len(vals): return False
            mx=max(quantity[j] for j in range(m) if ((1<<j) & mask)==0)
            if vals[start]<mx: return False
            if dfs(start+1, mask): return True

            for i in range(1<<m):
                if (i | mask)!=i: continue # new selection is a superset of existing set
                sum=0
                for j in range(m):
                    if ((1<<j) & i) and ((1<<j) & mask)==0:
                        sum+=quantity[j]

                if sum<=vals[start]:
                    if dfs(start+1, i): return True

            return False

        m=len(quantity)
        cnt=collections.Counter(nums)
        vals=sorted(cnt.values(), reverse=True)
        return dfs(0, 0)


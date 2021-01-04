class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        mod=10**9+7
        res=0
        dic=collections.defaultdict(int)
        for d in deliciousness:
            for i in range(22):
                sum=1<<i
                if sum-d in dic:
                    res=(res+dic[sum-d])%mod
            
            dic[d]+=1
        
        return res


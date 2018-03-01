import functools
class Solution:
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """                
        def comp(a, b):
            return -1 if a[0]<b[0] or (a[0]==b[0] and a[1]>b[1]) else 1
        envelopes.sort(key=functools.cmp_to_key(comp))
        
        res=[]
        for env in envelopes:
            l, r=0, len(res)
            while l<r:
                mid=int(l+(r-l)/2)
                if env[1]<=res[mid][1]:
                    r=mid
                else:
                    l=mid+1
            if l==len(res): res.append(env)
            else: res[l]=env
        
        return len(res)
            

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        def find(i):
            if i!=root[i]: root[i]=find(root[i])
            return root[i]
        
        res, n=0, len(source)
        root=[i for i in range(n)]
        for i, j in allowedSwaps:
            p1, p2=find(i), find(j)
            if p1!=p2: root[p1]=p2
            
        dic=defaultdict(lambda: defaultdict(int))
        for i, v in enumerate(source):
            p=find(i)
            dic[p][v]+=1
            
        for i, v in enumerate(target):
            p=find(i)
            if dic[p][v]>0:
                dic[p][v]-=1
            else:
                res+=1
                
        return res


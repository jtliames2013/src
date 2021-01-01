class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        def find(i):
            while i!=root[i]:
                root[i]=root[root[i]]
                i=root[i]
            return i
            
        m, n=len(matrix), len(matrix[0])
        res=[[0]*n for _ in range(m)]
        dic=collections.defaultdict(list)
        for i in range(m):
            for j in range(n):
                dic[matrix[i][j]].append([i, j])
            
        rank=[0]*(m+n)
        for k in sorted(dic):
            root=[i for i in range(m+n)]
            curr=rank[:]
            for i, j in dic[k]:
                p1=find(i)
                p2=find(j+m)
                if p1!=p2:
                    root[p1]=p2
                    curr[p2]=max(curr[p2], curr[p1])
            for i, j in dic[k]:
                res[i][j]=rank[i]=rank[j+m]=curr[find(i)]+1
        
        return res


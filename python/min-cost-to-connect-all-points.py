class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def find(i):
            while i!=root[i]:
                root[i]=root[root[i]]
                i=root[i]
            return i
        
        res, cnt, n=0, 0, len(points)
        conn, root=[], [i for i in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                conn.append([i, j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])])     
                    
        conn.sort(key=lambda c: c[2])
        for c in conn:
            p1=find(c[0])
            p2=find(c[1])
            if p1!=p2:
                cnt+=1
                res+=c[2]
                root[p1]=p2
            
            if cnt==n-1: break
        return res


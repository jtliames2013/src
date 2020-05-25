class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        res, m, n=[], len(mat), len(mat[0])
        pq=[]
        for i in range(m):
            cnt=0
            for j in range(n):
                if mat[i][j]==0: break
                cnt+=1
            if len(pq)<k: heappush(pq, [-cnt, -i])
            elif cnt<-pq[0][0]:
                heappop(pq);
                heappush(pq, [-cnt, -i])

        while pq:
            res.append(-heappop(pq)[1])
                
        return res[::-1]


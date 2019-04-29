ass Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        delta=[[-1,0], [1,0], [0,-1], [0,1]]
        res=[]
        visited=[[False for c in range(C)] for r in range(R)]
        q=[]
        q.append([r0,c0])
        visited[r0][c0]=True
        
        while len(q)>0:
            f=q.pop(0)
            res.append(f)
            
            for k in range(4):
                nr=f[0]+delta[k][0]
                nc=f[1]+delta[k][1]
                if nr>=0 and nr<R and nc>=0 and nc<C and visited[nr][nc]==False:
                    q.append([nr,nc])
                    visited[nr][nc]=True
        return res


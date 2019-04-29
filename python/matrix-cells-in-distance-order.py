class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        delta=[[-1,0], [1,0], [0,-1], [0,1]]
        res=[]        
        q=[[r0,c0]]
        visited={(r0,c0)}
        
        while len(q)>0:
            f=q.pop(0)
            res.append(f)
            
            for k in range(4):
                nr=f[0]+delta[k][0]
                nc=f[1]+delta[k][1]
                if 0<=nr<R and 0<=nc<C and (nr,nc) not in visited:
                    q.append([nr,nc])
                    visited.add((nr,nc))
        return res


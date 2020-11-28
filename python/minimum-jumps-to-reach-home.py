class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        res=0
        q, visited, mx=[(0, 0)], {(0, 0)}, max([x]+forbidden)+a+b
        for f in forbidden:
            visited.add((f, 1))
            visited.add((f, -1))
        
        while q:
            for _ in range(len(q)):
                pos, dir=q.pop(0)
                if pos==x: return res

                np=pos+a
                if np<=mx and (np, 1) not in visited:
                    q.append((np, 1))
                    visited.add((np, 1))
                if dir!=-1:
                    np=pos-b
                    if np>0 and (np, -1) not in visited:
                        q.append((np, -1))
                        visited.add((np, -1))

            res+=1
            
        return -1


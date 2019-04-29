class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        v=[a,b,c]
        v=sorted(v)
        mx=v[2]-v[0]-2
        if v[2]-v[0]==2:
            mi=0
        elif min(v[1]-v[0],v[2]-v[1])<=2:
            mi=1
        else:
            mi=2
        return [mi, mx]


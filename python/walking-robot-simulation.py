class Solution:
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        res=0
        delta=[[0,1], [1,0], [0,-1], [-1,0]]
        st=set(tuple(row) for row in obstacles)
        d=x=y=0
        for c in commands:
            if c==-1: d=(d+1)%4
            elif c==-2: d=(d-1)%4
            else:
                while c>0:
                    if (x+delta[d][0], y+delta[d][1]) in st: break
                    x+=delta[d][0]
                    y+=delta[d][1]
                    c-=1
            res=max(res, x**2+y**2)
        
        return res

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x,y,d=0,0,0
        delta=[[0,1],[1,0],[0,-1],[-1,0]]
        for i in instructions:
            if i=='G': x,y=x+delta[d][0],y+delta[d][1]
            elif i=='L': d=(d+3)%4
            else: d=(d+1)%4
        return (x==0 and y==0) or d>0

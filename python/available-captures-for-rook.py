class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res=0
        for i in range(8):
            for j in range(8):
                if board[i][j]=='R':
                    rx=i
                    ry=j
                    break
        for i, j in [[-1,0], [1,0], [0,-1], [0,1]]:
            x, y=rx+i, ry+j
            while 0<=x<8 and 0<=y<8:
                if board[x][y]=='p': res+=1
                if board[x][y]!='.': break
                x+=i
                y+=j
        return res

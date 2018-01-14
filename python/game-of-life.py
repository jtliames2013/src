class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        delta=[[-1,-1],[-1,0], [-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
        for i in range(m):
            for j in range(n):
                count=0
                for d in delta:
                    nr=i+d[0]
                    nc=j+d[1]
                    if nr>=0 and nr<m and nc>=0 and nc<n:
                        if board[nr][nc] & 0x1 == 1: count+=1
                        if count>3: break
                if board[i][j] & 0x1 == 1: 
                    if count==2 or count==3: board[i][j] |= 0x2
                else:
                    if count==3: board[i][j] |= 0x2
        
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
                

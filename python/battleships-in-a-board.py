class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        res, m, n=0, len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j]=='X':
                    if (i==0 or board[i-1][j]!='X') and (j==0 or board[i][j-1]!='X'): res+=1
        return res


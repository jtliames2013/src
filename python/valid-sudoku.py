class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows=[[0 for j in range(9)] for i in range(9)]
        cols=[[0 for j in range(9)] for i in range(9)]
        blocks=[[0 for j in range(9)] for i in range(9)]
        
        for i in range(9):
            for j in range(9):
                if board[i][j]!='.':
                    num=int(board[i][j])-1
                    b=(i//3)*3+j//3
                    if rows[i][num] or cols[j][num] or blocks[b][num]: return False
                    rows[i][num]=cols[j][num]=blocks[b][num]=1
        return True


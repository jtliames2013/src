class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(row, col, start):
            if start==len(word): return True
            if row<0 or row>=m or col<0 or col>=n: return False
            if board[row][col]!=word[start]: return False
            c=board[row][col]
            board[row][col]='#'
            if dfs(row+1, col, start+1) or \
               dfs(row-1, col, start+1) or \
               dfs(row, col+1, start+1) or \
               dfs(row, col-1, start+1): return True
            board[row][col]=c
            return False
            
        if not word: return False
        m, n=len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0): return True
        return False


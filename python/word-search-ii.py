class TrieNode:
    def __init__(self):
        self.children=collections.defaultdict(TrieNode)
        self.word=''

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(row, col, node):
            if node.word:
                res.append(node.word)
                node.word=''

            if row<0 or row>=m or col<0 or col>=n: return
            c=board[row][col]
            if c=='#'  or c not in node.children: return
            node=node.children[c]
            board[row][col]='#'
            dfs(row+1, col, node)
            dfs(row-1, col, node)
            dfs(row, col+1, node)
            dfs(row, col-1, node)
            board[row][col]=c

        res=[]
        m=len(board)
        if m==0: return res
        n=len(board[0])
        if n==0: return res
        root=TrieNode()
        for w in words:
            node=root
            for c in w:
                node=node.children[c]
            node.word=w

        for i in range(m):
            for j in range(n):
                dfs(i, j, root)

        return res


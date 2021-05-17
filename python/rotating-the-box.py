class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n=len(box), len(box[0])
        res=[['.']*m for _ in range(n)]
        for i in range(m):
            j, end=n-1, n-1
            while j>=0:
                if box[i][j]=='*':                    
                    res[j][m-i-1]='*'
                    end=j-1
                elif box[i][j]=='#':
                    res[end][m-i-1]='#'
                    end-=1
                j-=1
        
        return res


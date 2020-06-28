class Solution:
    def isPathCrossing(self, path: str) -> bool:
        st, row, col=set(), 0, 0
        st.add((0, 0))
        for p in path:
            if p=='N': row-=1
            elif p=='S': row+=1
            elif p=='E': col+=1
            elif p=='W': col-=1
            if (row, col) in st: return True
            st.add((row, col))
        return False


class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def dfs(start):
            if start==n: return 0
            res=0
            for i in range(start, n):
                if s[start:i+1] not in st:
                    st.add(s[start:i+1])
                    res=max(res, 1+dfs(i+1))
                    st.remove(s[start:i+1])
            return res
        
        st, n=set(), len(s)
        return dfs(0)


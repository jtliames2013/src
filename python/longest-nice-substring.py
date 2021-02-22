class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s)==1: return ""
        st=set()
        for c in s: st.add(c)
        for i, c in enumerate(s):
            if c.upper() in st and c.lower() in st: continue
            s1=self.longestNiceSubstring(s[0:i])
            s2=self.longestNiceSubstring(s[i+1:])
            return s1 if len(s1)>=len(s2) else s2
        return s


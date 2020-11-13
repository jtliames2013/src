class Solution:
    def minDeletions(self, s: str) -> int:
        res, count, st=0, collections.Counter(s), set()
        for v in count.values():
            while v>0 and v in st:
                v-=1
                res+=1
            st.add(v)
        
        return res


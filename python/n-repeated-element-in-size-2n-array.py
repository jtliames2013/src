class Solution:
    def repeatedNTimes(self, A: 'List[int]') -> 'int':
        st=set()
        for i in A:
            if i in st: return i
            st.add(i)
            
        return 0



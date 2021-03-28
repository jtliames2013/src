class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        st=set()
        i, n=0, len(word)
        while i<n:
            if word[i].isdigit():
                j=i
                while j<n and word[j].isdigit(): j+=1
                st.add(int(word[i:j])) 
                i=j
            else:
                i+=1
        return len(st)


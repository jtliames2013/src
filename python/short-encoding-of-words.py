class Solution:
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        st=set(words)
        for w in words:
            for i in range(1, len(w)):
                st.discard(w[i:])
        return sum(len(s)+1 for s in st)

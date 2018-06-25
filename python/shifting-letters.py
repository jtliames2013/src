ass Solution:
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        for i in range(len(shifts)-1)[::-1]:
            shifts[i]+=shifts[i+1]
        return ''.join(chr((ord(c)-ord('a')+i)%26+ord('a')) for c, i in zip(S, shifts))

class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A)!=len(B): return False
        diff=[(a, b) for a, b in zip(A, B) if a!=b]
        if len(diff)==0: return len(set(A))<len(A)
        return len(diff)==2 and diff[0]==diff[1][::-1]

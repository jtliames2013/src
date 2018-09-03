class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        d=collections.defaultdict(int)
        for w in A:
            even=''.join(sorted(w[0::2]))
            odd=''.join(sorted(w[1::2]))
            d[(even, odd)]+=1
        return len(d)

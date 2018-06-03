class Solution:
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        S=S[1:-1]
        def helper(s):
            if len(s)==0: return []
            if len(s)==1: return [s]
            if s[0]=='0' and s[-1]=='0': return []
            elif s[0]=='0': return ['0.'+s[1:]]
            elif s[-1]=='0': return [s]
            else:
                return [s]+[s[:i]+'.'+s[i:] for i in range(1,len(s))]
        return ['(%s, %s)' % (l, r) for i in range(len(S)) for l, r in itertools.product(helper(S[:i]), helper(S[i:]))]

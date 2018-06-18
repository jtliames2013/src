class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        country=["", "+*-", "+**-", "+***-"]
        pos=S.find('@')
        if pos>=0:
            return (S[0] + "*"*5 + S[pos-1:]).lower()
        else:
            S="".join(c for c in S if c.isdigit())
            return country[len(S)-10]+"***-***-"+S[-4:]

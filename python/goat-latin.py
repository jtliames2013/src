class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        vowel = set('aeiou')
        def getWord(i, w):
            if w[0].lower() not in vowel:
                w=w[1:]+w[0]
            return w+"ma"+'a'*(i+1)
        
        return ' '.join(getWord(i,w) for i, w in enumerate(S.split()))

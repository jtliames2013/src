class Solution:    
    def toGoatLatin(self, S: str) -> str:
        vowels=set('aeiouAEIOU')
        def latin(word, i):
            if word[0] not in vowels:
                word=word[1:]+word[0]
            return word+"ma"+'a'*(i+1)

        return ' '.join(latin(w, i) for i, w in enumerate(S.split()))


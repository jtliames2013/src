class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:           
        s1, s2=sentence1.split(), sentence2.split()
        n1, n2=len(s1), len(s2)
        if n1<n2:
            return self.areSentencesSimilar(sentence2, sentence1)
        
        i=0
        while i<n2 and s1[i]==s2[i]: i+=1
        while i<n2 and s1[n1-n2+i]==s2[i]: i+=1
        return i==n2


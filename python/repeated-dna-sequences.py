class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res=[]
        mp={'A':0, 'C':1, 'G':2, 'T':3}
        d=collections.defaultdict(int)
        num=0
        for i, c in enumerate(s):
            num=((num<<2) | mp[c]) & 0xfffff
            if i>=9:
                if d[num]==1: res.append(s[i-9:i+1])
                d[num]+=1
        
        return res    

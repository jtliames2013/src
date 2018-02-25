class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mp={'M': 1000,'D': 500 ,'C': 100,'L': 50,'X': 10,'V': 5,'I': 1}
        res=0
        for i in range(0, len(s)-1):
            if mp[s[i]]<mp[s[i+1]]:
                res-=mp[s[i]]
            else:
                res+=mp[s[i]]
        return res+mp[s[-1]]
        

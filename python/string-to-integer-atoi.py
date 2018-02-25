class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str=str.strip()
        if len(str)==0: return 0
        i=0
        neg=False
        if str[i]=='+' or str[i]=='-':
            neg=True if str[i]=='-' else False
            i+=1
        
        res=0
        while i<len(str) and str[i].isdigit():
            res=res*10+ord(str[i])-ord('0')
            if res>2**31-1:
                return 2**31-1 if neg==False else -2**31
            i+=1
        
        return res if neg==False else -res

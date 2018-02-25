class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if divisor==0:
            return 2**31-1 if dividend!=0 else -2**31
        if dividend==-2**31 and divisor==-1:
            return 2**31-1
        
        res=0
        neg=(dividend>0) is not (divisor>0)        
        dd, dr=abs(dividend), abs(divisor)
        while (dd>=dr):
            i=0
            while (dd>=(dr<<i)): i+=1
            i-=1
            res+=1<<i
            dd-=(dr<<i)
        return res if neg==False else -res

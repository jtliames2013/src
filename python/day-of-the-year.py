class Solution:
    def dayOfYear(self, date: str) -> int:
        days=[31,28,31,30,31,30,31,31,30,31,30,31]
        y,m,d=map(int, date.split('-'))
        leap=(y%400==0) or (y%4==0 and y%100!=0)
        res=d
        for i in range(m-1):
            res+=days[i]
            if i==1 and leap:
                res+=1
                
        return res
